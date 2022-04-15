/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_diu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:58:43 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 15:18:13 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(t_print *acc, int n)
{
	if (n == -2147483648)
	{
		acc->res_len += ft_putstr("2147483648", 10);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr(acc, n / 10);
		acc->res_len += ft_putchar(n % 10 + '0');
	}
	else
		acc->res_len += ft_putchar(n + '0');
}

void	ft_u_putnbr(t_print *acc, unsigned int n)
{
	if (n == 4294967295)
	{
		acc->res_len += ft_putstr("4294967295", 10);
		return ;
	}
	if (n < 0)
	{
		acc->res_len += ft_putchar('-');
		ft_putnbr(acc, UINT_MAX + n + 1);
	}
	if (n > 9)
	{
		ft_u_putnbr(acc, n / 10);
		acc->res_len += ft_putchar((n % 10) + '0');
	}
	else
		acc->res_len += ft_putchar(n + '0');
}

int	check_no_precision(const char *fmt, t_print *acc, int n)
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

void	ft_print_di(const char *fmt, t_print *acc)
{
	int	n;
	int	no_precision;
	int	minus_sign;

	n = va_arg(acc->args, int);
	no_precision = 1;
	minus_sign = 0;
	check_int_minus(acc, &minus_sign, &n);
	acc->con_len += get_intsize(n);
	if (!check_no_precision(fmt, acc, n))
		no_precision = 0;
	ft_use_width(fmt, acc);
	ft_use_plus(fmt, acc);
	ft_use_space(fmt, acc);
	if (minus_sign == 1)
		acc->res_len += ft_putchar('-');
	ft_use_precision(fmt, acc);
	ft_use_zero(fmt, acc);
	if (no_precision == 0)
		ft_putnbr(acc, n);
	ft_use_minus(fmt, acc);
}

void	ft_print_u(const char *fmt, t_print *acc)
{
	unsigned int	n;
	int				no_precision;

	n = va_arg(acc->args, unsigned int);
	if (n < 0)
		n = UINT_MAX + n + 1;
	no_precision = 1;
	acc->con_len += get_u_intsize(n);
	if (!check_no_precision(fmt, acc, n))
		no_precision = 0;
	ft_use_width(fmt, acc);
	ft_use_precision(fmt, acc);
	ft_use_zero(fmt, acc);
	if (no_precision == 0)
		ft_u_putnbr(acc, n);
	ft_use_minus(fmt, acc);
}
