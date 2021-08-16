/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 19:19:17 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/22 16:21:19 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	elsepointers(t_tab *tab)
{
	if (tab->precission == -1 && tab->zero == 1)
		zero(tab);
	write_blanks_p(tab);
	write(1, "0x", 2);
	write_zeroes_p(tab);
	if (tab->nb != 0 || (tab->width == 0 && tab->precission == -1) ||
	(tab->width != 0 && tab->precission == -1 && tab->nb == 0 &&
	tab->zero == 1))
	{
		ft_putnbr_p(tab->nb, tab);
	}
}

int		pointers(t_tab *tab)
{
	asterisk(tab);
	ft_length_p(tab->nb, tab);
	if (tab->width == 0 && tab->precission == -1 && tab->zero == 0 &&
	tab->minus == 0 && tab->negative == 0 && tab->nb == 0)
	{
		write(1, "0x", 2);
		ft_putnbr_p(tab->nb, tab);
	}
	else if (tab->width > tab->precission && tab->minus == 1 && tab->zero == 0)
	{
		write_zeroes_p(tab);
		if (tab->nb != 0 || (tab->width != 0 && tab->precission == -1 &&
		tab->nb == 0))
		{
			write(1, "0x", 2);
			ft_putnbr_p(tab->nb, tab);
		}
		write_blanks_p(tab);
	}
	else
		elsepointers(tab);
	return (tab->cnt_length);
}
