/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_blanks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:22:47 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/03/09 10:07:35 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_blanks(t_tab *tab)
{
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

void	write_zeroes(t_tab *tab)
{
	int		precission;

	precission = tab->precission - tab->cnt_length + tab->negative;
	if (tab->nb == 0 && tab->negative == 1)
		write(1, "0", 1);
	while (precission > 0)
	{
		tab->cnt_chars++;
		write(1, "0", 1);
		precission--;
	}
}
