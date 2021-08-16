/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:14:31 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/20 20:06:56 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	zero(t_tab *tab)
{
	if (tab->precission == -1 && tab->zero == 1 && tab->minus == 0)
		tab->width = tab->width - tab->cnt_length;
	while (tab->width > 0)
	{
		tab->cnt_chars++;
		write(1, "0", 1);
		tab->width--;
	}
}
