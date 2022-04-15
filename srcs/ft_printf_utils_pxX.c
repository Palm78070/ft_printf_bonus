/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_pxX.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:59:45 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 18:15:26 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag_px(const char *fmt, t_print *acc)
{
	acc->con_len += 1;
	if (acc->con == 'p')
	{
		acc->hash = 1;
		acc->con_len += 2;
	}
	ft_use_width(fmt, acc);
	ft_use_precision(fmt, acc);
	ft_use_zero(fmt, acc);
	ft_use_hash(acc);
}

void	ft_print_hex(const char *fmt, uintptr_t n, t_print *acc)
{
	int	mod;

	if (acc->con != 'p')
		n = (unsigned int)n;
	if (n >= 16)
	{
		acc->con_len += 1;
		ft_print_hex(fmt, (n / 16), acc);
	}
	if (n < 16)
	{
		check_flag_px(fmt, acc);
		if (acc->con_len == -1)
			return ;
	}
	mod = n % 16;
	if (mod >= 0 && mod < 10)
		acc->res_len += ft_putchar(mod + '0');
	else
	{
		if (acc->con == 'X')
			acc->res_len += ft_putchar(('A' - 10) + mod);
		else
			acc->res_len += ft_putchar(('a' - 10) + mod);
	}
}

void	print_address_hex(const char *fmt, void *ptr, t_print *acc)
{
	uintptr_t	addrs_dec;

	addrs_dec = (uintptr_t)ptr;
	ft_print_hex(fmt, addrs_dec, acc);
	ft_use_minus(fmt, acc);
}

void	ft_print_x(const char *fmt, t_print *acc)
{
	unsigned int	n;

	n = va_arg(acc->args, unsigned int);
	if (n == 0)
		acc->hash = 0;
	if (!(check_no_uprecision(fmt, acc, n)))
		ft_print_hex(fmt, n, acc);
	else
		check_flag_px(fmt, acc);
	ft_use_minus(fmt, acc);
}
