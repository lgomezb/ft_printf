/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:13:44 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/20 19:41:59 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		chars(t_tab *tab)
{
	tab->width--;
	if (tab->width == 0)
		ft_putchar(tab);
	else
	{
		if (tab->minus == 0)
		{
			while (tab->width > 0)
			{
				tab->cnt_chars++;
				write(1, " ", 1);
				tab->width--;
			}
		}
		ft_putchar(tab);
		if (tab->minus != 0)
		{
			while (tab->width > 0)
			{
				tab->cnt_chars++;
				write(1, " ", 1);
				tab->width--;
			}
		}
	}
}
