/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_len.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:07:21 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 18:10:23 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	count_dot_len(const char *fmt, t_print *acc)
{
	int	indx;
	int	width_p;
	int	i;

	width_p = 0;
	indx = acc->precision;
	i = -1;
	if (acc->con_len == -1)
		acc->con_len = 0;
	if (indx > 0)
	{
		if (ft_isdigit(fmt[indx + 1]))
			acc->zero = 0;
		while (ft_isdigit(fmt[++indx]))
			width_p = (width_p * 10) + (fmt[indx] - '0');
		if (acc->con == 's' && (width_p <= (acc->con_len)))
			acc->dot_len = (acc->con_len) - width_p;
		else if (acc->con != 's' && (width_p > acc->con_len))
			acc->dot_len = width_p - acc->con_len;
	}
}

int	get_intsize(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	if (n < 0 && ++res)
		n *= (-1);
	while (n > 0 && ++res)
		n /= 10;
	return (res);
}

int	get_u_intsize(unsigned int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n == 4294967295)
		return (10);
	while (n > 0 && ++res)
		n /= 10;
	return (res);
}
