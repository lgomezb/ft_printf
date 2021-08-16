/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 21:36:04 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/22 17:02:23 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	elsehexa(t_tab *tab)
{
	if (tab->precission == -1 && tab->zero == 1)
		zero(tab);
	write_blanks_x(tab);
	write_zeroes_hx(tab);
	if (tab->nb != 0 || (tab->width == 0 && tab->precission == -1) ||
	(tab->width != 0 && tab->precission == -1 && tab->nb == 0 &&
	tab->zero == 1))
		ft_putnbr_hex(tab->nb, tab);
}

void	elseifhexa(t_tab *tab)
{
	write_zeroes_hx(tab);
	if (tab->nb != 0 || (tab->width != 0 && tab->precission == -1 &&
	tab->nb == 0))
		ft_putnbr_hex(tab->nb, tab);
	write_blanks_x(tab);
}

int		hexadecimal(t_tab *tab)
{
	asterisk(tab);
	ft_length_x(tab->nb, tab);
	if (tab->width == 0 && tab->precission == -1 && tab->zero == 0 &&
	tab->minus == 0 && tab->negative == 0 && tab->nb == 0)
		ft_putnbr_hex(tab->nb, tab);
	else if (tab->width > tab->precission && tab->minus == 1 && tab->zero == 0)
		elseifhexa(tab);
	else
		elsehexa(tab);
	return (tab->cnt_length);
}
