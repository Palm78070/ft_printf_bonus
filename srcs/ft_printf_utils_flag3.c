/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_flag3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:50:20 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 17:03:15 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_before_num(const char *fmt, t_print *acc, int indx)
{
	char	con;

	con = fmt[indx];
	while (fmt[++indx])
	{
		if (ft_iscon(fmt[indx]))
		{
			if (con == ' ')
				acc->space = 1;
			else if (con == '+')
				acc->plus = 1;
			return (1);
		}
	}
	return (0);
}

void	ft_check_zero(const char *fmt, int i, t_print *acc)
{
	int	j;

	j = i - 1;
	if (fmt[j] == '%' || fmt[j] == ' ')
		acc->zero = i;
}

void	ft_use_plus(const char *fmt, t_print *acc)
{
	int	i;
	int	before_num;

	i = acc->plus;
	if (acc->plus <= 0)
		return ;
	before_num = is_before_num(fmt, acc, i);
	if ((acc->con != 'i' && acc->con != 'd') || !before_num)
	{
		acc->plus = 0;
		return ;
	}
	acc->res_len += ft_putchar('+');
}

void	check_int_minus(t_print *acc, int *minus_sign, int *n)
{
	if (*n < 0)
	{
		acc->plus = -1;
		*minus_sign = 1;
		if (*n != -2147483648)
			(*n) *= -1;
	}
}
