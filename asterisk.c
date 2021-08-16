/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:21:39 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/22 18:11:54 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	awz(t_tab *tab)
{
	if (tab->precission < -1)
	{
		tab->asterisk++;
		if (tab->minus == 0)
			tab->minus = 1;
		else
			tab->minus = 0;
		if (tab->precission < -1 && tab->minus == 0)
			tab->precission = -tab->precission;
		if (tab->minus == 1)
			tab->precission = -1;
	}
	if (tab->zero == 1 && tab->minus == 1 && tab->asterisk != 0)
	{
		tab->asterisk++;
		tab->minus = 1;
		tab->zero = 0;
	}
}

void	asterisk(t_tab *tab)
{
	if (tab->asterisk != 0)
	{
		if (tab->minus == 1)
		{
			tab->asterisk++;
			if (tab->width < 0)
				tab->width = -tab->width;
			if (tab->precission < -1)
				tab->precission = -1;
		}
		if (tab->width < 0)
		{
			tab->asterisk++;
			if (tab->minus == 0)
				tab->minus = 1;
			else
				tab->minus = 0;
			if (tab->width < 0)
				tab->width = -tab->width;
		}
		awz(tab);
	}
}
