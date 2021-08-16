/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 13:18:12 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/03/09 10:03:01 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_length_p(unsigned long int n, t_tab *tab)
{
	char *base;

	tab->cnt_length = 2;
	if (tab->nb == 0 && tab->precission)
		tab->cnt_length++;
	base = "0123456789abcdef";
	tab->cnt_chars = tab->cnt_chars + 2;
	while (n > 0)
	{
		n /= 16;
		tab->cnt_length++;
	}
}

void	ft_length_x(long long int n, t_tab *tab)
{
	char *base;

	base = "0123456789abcdef";
	if (n == 0 && tab->width != 0 && tab->zero == 1 && tab->precission == -1)
		tab->cnt_length++;
	while (n > 0)
	{
		n /= 16;
		tab->cnt_length++;
	}
}

void	ft_length(long n, t_tab *tab)
{
	if (n < 0)
	{
		tab->negative++;
		n = -n;
	}
	else if (n == 0)
	{
		if (tab->precission == -1)
			tab->cnt_length++;
	}
	while (n > 0)
	{
		n /= 10;
		tab->cnt_length++;
	}
}
