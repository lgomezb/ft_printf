/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_blanks_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:39:33 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/20 20:06:34 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_blanks_p(t_tab *tab)
{
	if (tab->precission > tab->cnt_length)
		tab->width = tab->width - tab->precission - tab->cnt_chars;
	else
		tab->width = tab->width - tab->cnt_length;
	while (tab->width > 0)
	{
		tab->cnt_chars++;
		write(1, " ", 1);
		tab->width--;
	}
	tab->width = 0;
}

void	write_zeroes_p(t_tab *tab)
{
	int		precission;

	precission = tab->precission - tab->cnt_length + tab->negative;
	while (precission > 0)
	{
		tab->cnt_chars++;
		write(1, "0", 1);
		precission--;
	}
}
