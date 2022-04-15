/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:40:31 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 10:42:09 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	if (s == NULL)
		return (6);
	while (*s)
	{
		++s;
		++n;
	}
	return (n);
}

int	ft_instr(char c, char *s)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}
