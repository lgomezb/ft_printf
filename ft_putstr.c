/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:40:28 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/02/20 18:58:47 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(t_tab *tab)
{
	int		i;
	int		cnt;

	cnt = 0;
	if (tab->precission < tab->cnt_length && tab->precission != -1)
		i = tab->precission;
	else
		i = tab->cnt_length;
	if (tab->str)
	{
		while (i > 0)
		{
			write(1, &tab->str[cnt], 1);
			i--;
			cnt++;
			tab->cnt_chars++;
		}
	}
}
