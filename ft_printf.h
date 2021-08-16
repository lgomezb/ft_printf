/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:55:48 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/22 18:20:05 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct			s_tab
{
	int					minus;
	int					zero;
	int					asterisk;
	int					precission;
	int					width;
	long long int		nb;
	int					i;
	int					cnt_zero;
	int					cnt_chars;
	int					cnt_length;
	int					negative;
	char				type;
	char				*str;
	char				*aux_zero;
	char				c;
	unsigned long int	pointer;
	const char			*format;
	int					prueba;
	va_list				ap;
}						t_tab;

int						ft_printf(const char *format, ...);
void					chars(t_tab *tab);
void					flags(const char *format, t_tab *tab, va_list ap);
void					ft_length(long n, t_tab *tab);
void					ft_putchar(t_tab *tab);
void					ft_putnbr(long long int n, t_tab *tab);
void					ft_putnbr_hex(long long int n, t_tab *tab);
void					ft_putnbr_p(unsigned long int n, t_tab *tab);
void					ft_putstr(t_tab *tab);
void					ft_strlen(t_tab *tab);
void					integers(t_tab *tab);
int						hexadecimal(t_tab *tab);
void					precission (t_tab *tab);
void					write_zeroes(t_tab *tab);
void					write_zeroes_hx(t_tab *tab);
void					write_zeroes_p(t_tab *tab);
void					width (t_tab *tab);
void					zero(t_tab *tab);
void					strings(t_tab *tab);
int						pointers(t_tab *tab);
void					pcnt(t_tab *tab);
void					write_blanks(t_tab *tab);
void					write_blanks_x(t_tab *tab);
void					write_blanks_p(t_tab *tab);
void					ft_length_x(long long int n, t_tab *tab);
void					ft_length_p(unsigned long int n, t_tab *tab);
void					asterisk(t_tab *tab);
void					reiniflags(t_tab *tab);
void					initflags(t_tab *tab);

#endif
