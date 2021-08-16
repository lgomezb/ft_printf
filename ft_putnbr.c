/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:18:12 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/22 18:19:55 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr(long long int n, t_tab *tab)
{
	long long int	un;

	un = 0;
	if (n < 0)
		un = n * -1;
	else
		un = n;
	if (un >= 10)
		ft_putnbr(un / 10, tab);
	un = (un % 10) + 48;
	write(1, &un, 1);
	tab->cnt_chars++;
}

void	ft_putnbr_hex(long long int n, t_tab *tab)
{
	char *base;

	n = (unsigned)n;
	if (tab->type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_hex(n / 16, tab);
	write(1, &base[n % 16], 1);
	tab->cnt_chars++;
}

void	ft_putnbr_p(unsigned long int n, t_tab *tab)
{
	char *base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_p(n / 16, tab);
	tab->cnt_chars++;
	write(1, &base[n % 16], 1);
}
