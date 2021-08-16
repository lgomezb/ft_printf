/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:39:05 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/20 20:05:58 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ifstrings(t_tab *tab)
{
	if (tab->minus == 0)
	{
		if (tab->cnt_length > tab->precission)
			tab->cnt_length = tab->precission;
		if (tab->zero == 1)
			write_zeroes(tab);
		else
			write_blanks(tab);
	}
	ft_putstr(tab);
	if (tab->minus == 1)
	{
		tab->cnt_length = tab->precission;
		write_blanks(tab);
	}
}

void	strings(t_tab *tab)
{
	ft_strlen(tab);
	asterisk(tab);
	if (tab->precission < tab->cnt_length && tab->precission != -1)
	{
		if (tab->width >= tab->precission)
			ifstrings(tab);
		else
			ft_putstr(tab);
	}
	else
	{
		if (tab->width >= tab->precission)
		{
			if (tab->minus == 0)
				write_blanks(tab);
			ft_putstr(tab);
			if (tab->minus == 1)
				write_blanks(tab);
		}
		else
		{
			write_blanks(tab);
			ft_putstr(tab);
		}
	}
}
