/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:22:38 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/03/09 09:52:05 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strlen(t_tab *tab)
{
	int		count;
	char	*aux;

	aux = NULL;
	aux = tab->str;
	count = 0;
	while (*aux != '\0')
	{
		aux++;
		count++;
	}
	tab->cnt_length = count;
}
