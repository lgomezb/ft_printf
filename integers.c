/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:09:32 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/03/09 10:08:55 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		elseintegers(t_tab *tab)
{
	if (tab->precission == -1 && tab->zero == 1)
	{
		if (tab->negative == 1)
		{
			tab->cnt_length++;
			tab->cnt_chars++;
			write(1, "-", 1);
			tab->negative = 0;
		}
		zero(tab);
	}
	write_blanks(tab);
	if (tab->negative == 1)
	{
		tab->cnt_length++;
		tab->cnt_chars++;
		write(1, "-", 1);
	}
	write_zeroes(tab);
	if (tab->nb != 0 || (tab->width == 0 && tab->precission == -1)
	|| (tab->width != 0 && tab->precission == -1 && tab->nb == 0
	&& tab->zero == 1))
		ft_putnbr(tab->nb, tab);
}

void		integers(t_tab *tab)
{
	asterisk(tab);
	ft_length(tab->nb, tab);
	if (tab->width == 0 && tab->precission == -1 && tab->zero == 0 &&
	tab->minus == 0 && tab->negative == 0 && tab->nb == 0)
		ft_putnbr(tab->nb, tab);
	else if (tab->width > tab->precission && tab->minus == 1 && tab->zero == 0)
	{
		if (tab->negative == 1)
		{
			tab->cnt_length++;
			tab->cnt_chars++;
			write(1, "-", 1);
		}
		write_zeroes(tab);
		if (tab->nb != 0 || (tab->width != 0 && tab->precission == -1 &&
		tab->nb == 0))
			ft_putnbr(tab->nb, tab);
		write_blanks(tab);
	}
	else
		elseintegers(tab);
}
