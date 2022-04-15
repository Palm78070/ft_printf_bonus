/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_flag2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:48:24 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 16:49:53 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_width(const char *fmt, int i, t_print *acc)
{
	int	j;

	j = i - 1;
	if ((fmt[j] == '%') || (fmt[j] == '#') || fmt[j] == ' ' \
	|| fmt[j] == '+')
		acc->width = i;
}

void	ft_use_hash(t_print *acc)
{
	if (!(acc->hash))
		return ;
	if (acc->con == 'p' || acc->con == 'x')
		acc->res_len += ft_putstr("0x", 2);
	else if (acc->con == 'X')
		acc->res_len += ft_putstr("0X", 2);
}

void	ft_use_zero(const char *fmt, t_print *acc)
{
	int	width;
	int	indx_z;

	width = 0;
	indx_z = acc->zero + 1;
	if (!(acc->zero) || (acc->minus))
		return ;
	while (ft_isdigit(fmt[indx_z]))
		width = (width * 10) + (fmt[indx_z++] - '0');
	if (width < (acc->con_len - acc->precision))
		return ;
	width -= (acc->con_len - acc->precision);
	if (acc->plus == -1)
		--width;
	while (width > 0)
	{
		acc->res_len += ft_putchar('0');
		--width;
	}
}

int	check_no_uprecision(const char *fmt, t_print *acc, unsigned int n)
{
	int	indx;

	indx = acc->precision + 1;
	if (acc->precision && n == 0)
	{
		if (fmt[indx] == '0' || !(ft_isdigit(fmt[indx])))
		{
			acc->zero = 0;
			acc->con_len = -1;
			return (1);
		}
	}
	return (0);
}

void	ft_use_space(const char *fmt, t_print *acc)
{
	int	i;
	int	before_num;

	i = acc->space;
	if (acc->space == 0)
		return ;
	before_num = is_before_num(fmt, acc, i);
	if (acc->plus || acc->plus == -1 || !(before_num))
	{
		acc->space = 0;
		return ;
	}
	acc->res_len += ft_putchar(' ');
}
