/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pcnt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:39:05 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/20 16:25:44 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pcnt(t_tab *tab)
{
	tab->cnt_length++;
	asterisk(tab);
	if (tab->width > 1)
	{
		if (tab->zero == 1)
			zero(tab);
		if (tab->minus == 0)
			write_blanks(tab);
		write(1, "%", 1);
		tab->cnt_chars++;
		if (tab->minus == 1)
			write_blanks(tab);
	}
	else
	{
		write(1, "%", 1);
		tab->cnt_chars++;
	}
}
