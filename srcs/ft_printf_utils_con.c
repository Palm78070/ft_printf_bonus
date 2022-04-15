/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_con.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:42:54 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 18:14:32 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_iscon(char c)
{
	return (ft_instr(c, "cspdiuxX"));
}

void	ft_check_con(const char *fmt, int i, t_print *acc)
{
	acc->con = fmt[i];
	if (fmt[i] == 'c')
		ft_print_c(fmt, acc);
	if (fmt[i] == 's')
		ft_print_s(fmt, acc);
	if (fmt[i] == 'p')
		print_address_hex(fmt, va_arg(acc->args, void *), acc);
	if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_print_di(fmt, acc);
	if (fmt[i] == 'u')
		ft_print_u(fmt, acc);
	if (fmt[i] == 'x' || fmt[i] == 'X')
		ft_print_x(fmt, acc);
}
