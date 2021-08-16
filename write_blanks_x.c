/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_blanks_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:39:33 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/22 18:19:28 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_blanks_x(t_tab *tab)
{
	if (tab->nb == 0 && tab->precission == -1)
		tab->width--;
	if (tab->precission > tab->cnt_length && tab->type != 's')
		tab->width = tab->width - tab->precission - tab->negative;
	else if (tab->negative == 1 && tab->minus == 1)
		tab->width = tab->width - tab->cnt_length;
	else
		tab->width = tab->width - tab->cnt_length - tab->negative;
	while (tab->width > 0)
	{
		tab->cnt_chars++;
		write(1, " ", 1);
		tab->width--;
	}
}

void	write_zeroes_hx(t_tab *tab)
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
