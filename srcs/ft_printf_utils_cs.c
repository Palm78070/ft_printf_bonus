/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_cs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:45:37 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 10:46:54 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str, int con_len)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (count += write(1, "(null)", con_len));
	while (*str && con_len > 0)
	{
		count += ft_putchar(*str++);
		--con_len;
	}
	return (count);
}

void	ft_print_c(const char *fmt, t_print *acc)
{
	acc->con_len = 1;
	if (!(acc->minus))
		ft_use_width(fmt, acc);
	acc->res_len += ft_putchar(va_arg(acc->args, int));
	ft_use_minus(fmt, acc);
}

void	ft_print_s(const char *fmt, t_print *acc)
{
	char	*str;

	str = va_arg(acc->args, char *);
	if (acc->space > 0 && acc->con == 's')
		acc->space = 0;
	acc->con_len = ft_strlen(str);
	if (acc->precision)
		ft_use_precision(fmt, acc);
	if (!(acc->minus))
		ft_use_width(fmt, acc);
	acc->res_len += ft_putstr(str, acc->con_len - acc->dot_len);
	ft_use_minus(fmt, acc);
}
