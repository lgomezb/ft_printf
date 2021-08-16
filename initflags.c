/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initflags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:39:56 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/20 20:23:19 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		reiniflags(t_tab *tab)
{
	tab->minus = 0;
	tab->precission = -1;
	tab->zero = 0;
	tab->asterisk = 0;
	tab->width = 0;
	tab->negative = 0;
	tab->str = NULL;
	tab->cnt_length = 0;
}

void		initflags(t_tab *tab)
{
	tab->minus = 0;
	tab->precission = -1;
	tab->zero = 0;
	tab->asterisk = 0;
	tab->width = 0;
	tab->i = 0;
	tab->cnt_chars = 0;
	tab->negative = 0;
	tab->str = NULL;
	tab->cnt_length = 0;
}
