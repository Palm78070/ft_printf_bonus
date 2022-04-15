/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 23:25:00 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/13 23:33:11 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_print	*acc;
	int		i;

	acc = (t_print *)malloc(sizeof(t_print));
	if (!acc)
		return (-1);
	acc->res_len = 0;
	va_start(acc->args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
			acc->res_len += ft_putchar(fmt[i++]);
		if (fmt[i] == '%')
		{
			ft_init_flag(acc);
			i = ft_check_flag(fmt, i, acc);
		}
	}
	i = acc->res_len;
	va_end(acc->args);
	free(acc);
	return (i);
}
