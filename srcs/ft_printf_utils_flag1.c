/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_flag1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:32:57 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 16:48:12 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flag(t_print *acc)
{
	acc->zero = 0;
	acc->minus = 0;
	acc->plus = 0;
	acc->precision = 0;
	acc->width = 0;
	acc->hash = 0;
	acc->space = 0;
	acc->con_len = 0;
	acc->con = 0;
	acc->dot_len = 0;
}

int	ft_check_flag(const char *fmt, int i, t_print *acc)
{
	while (!(ft_iscon(fmt[++i])))
	{
		if (fmt[i] == '%')
		{
			acc->res_len = (acc->res_len) + ft_putchar('%');
			return (i + 1);
		}
		if (fmt[i] == '0')
			ft_check_zero(fmt, i, acc);
		if (fmt[i] == '-')
			acc->minus = i;
		if (fmt[i] == ' ')
			acc->space = i;
		if (fmt[i] == '+')
			acc->plus = i;
		if (fmt[i] == '#')
			acc->hash = 1;
		if (ft_isdigit(fmt[i]))
			ft_check_width(fmt, i, acc);
		if (fmt[i] == '.')
			acc->precision = i;
	}
	ft_check_con(fmt, i, acc);
	return (i + 1);
}

void	ft_use_precision(const char *fmt, t_print *acc)
{
	int	indx;
	int	width_p;
	int	i;

	width_p = 0;
	indx = acc->precision;
	i = -1;
	if (indx > 0)
	{
		count_dot_len(fmt, acc);
		if (acc->con != 's' && acc->dot_len)
		{
			acc->precision = acc->dot_len;
			while (++i < acc->precision)
			{
				acc->res_len += ft_putchar('0');
				acc->con_len += 1;
			}
		}
		else
			acc->precision = 0;
	}
}

void	ft_use_width(const char *fmt, t_print *acc)
{
	int	width;
	int	indx_w;
	int	print_len;

	width = 0;
	indx_w = acc->width;
	count_dot_len(fmt, acc);
	print_len = acc->con_len + acc->dot_len + acc->space;
	if (acc->plus == -1 || acc->plus == 1)
		++print_len;
	if (acc->width && !(acc->minus) && !(acc->zero))
	{
		while (ft_isdigit(fmt[indx_w]))
			width = (width * 10) + (fmt[indx_w++] - '0');
		if (width >= (print_len))
		{
			width -= (print_len);
			while (width > 0)
			{
				acc->res_len += ft_putchar(' ');
				--width;
			}
		}
	}
}

void	ft_use_minus(const char *fmt, t_print *acc)
{
	int	width;
	int	indx_w;

	width = 0;
	indx_w = (acc->minus) + 1;
	if ((acc->minus) && (ft_isdigit(fmt[indx_w])))
	{
		while (ft_isdigit(fmt[indx_w]))
			width = (width * 10) + (fmt[indx_w++] - '0');
		if (acc->con == 's')
			width -= (acc->con_len - acc->dot_len);
		else
			width -= acc->con_len;
		if (acc->plus == -1)
			--width;
		while (width > 0)
		{
			(acc->res_len) += ft_putchar(' ');
			--width;
		}
	}
}
