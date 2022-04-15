/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:57:17 by rthammat          #+#    #+#             */
/*   Updated: 2022/04/14 18:13:13 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

typedef struct f_print
{
	va_list	args;
	int		zero;
	int		minus;
	int		plus;
	int		precision;
	int		width;
	int		hash;
	int		space;
	int		res_len;
	int		con_len;
	char	con;
	char	dot_len;
}	t_print;

int				ft_isdigit(int c);
int				is_before_num(const char *fmt, t_print *acc, int indx);
int				ft_strlen(const char *s);
int				ft_instr(char c, char *s);
int				get_intsize(int n);
int				get_u_intsize(unsigned int n);

int				ft_iscon(char c);
void			ft_check_con(const char *fmt, int i, t_print *acc);

void			ft_init_flag(t_print *acc);
int				ft_check_flag(const char *fmt, int i, t_print *acc);
int				check_no_uprecision(const char *fmt, t_print *acc, \
		unsigned int n);
void			ft_use_precision(const char *fmt, t_print *acc);
void			ft_check_width(const char *fmt, int i, t_print *acc);
void			ft_use_width(const char *fmt, t_print *acc);
void			ft_use_minus(const char *fmt, t_print *acc);

void			ft_use_hash(t_print *acc);
void			ft_check_zero(const char *fmt, int i, t_print *acc);
void			ft_use_zero(const char *fmt, t_print *acc);
void			ft_use_space(const char *fmt, t_print *acc);
void			ft_use_plus(const char *fmt, t_print *acc);

int				ft_putchar(int c);
int				ft_putstr(char *str, int con_len);

void			ft_putnbr(t_print *acc, int n);
void			ft_u_putnbr(t_print *acc, unsigned int n);

void			ft_print_hex(const char *fmt, uintptr_t n, t_print *acc);
void			print_address_hex(const char *fmt, void *ptr, t_print *acc);

void			ft_print_c(const char *fmt, t_print *acc);
void			ft_print_s(const char *fmt, t_print *acc);
void			ft_print_x(const char *fmt, t_print *acc);
void			check_int_minus(t_print *acc, int *minus_sign, int *n);
void			ft_print_di(const char *fmt, t_print *acc);
void			ft_print_u(const char *fmt, t_print *acc);

void			count_dot_len(const char *fmt, t_print *acc);

int				ft_printf(const char *fmt, ...);

#endif 
