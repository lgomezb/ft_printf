/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:31:32 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/03/09 09:58:40 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	star(t_tab *tab, va_list ap)
{
	tab->width = va_arg(ap, int);
	tab->i++;
	tab->asterisk++;
}

void	flags_asterisk_point(const char *format, t_tab *tab, va_list ap)
{
	if (format[tab->i] == '*')
		star(tab, ap);
	while ((format[tab->i] >= '0' && format[tab->i] <= '9')
	|| format[tab->i] == '*')
	{
		tab->width = tab->width * 10 + (format[tab->i] - '0');
		tab->i++;
	}
	if (format[tab->i] == '.')
	{
		tab->i++;
		tab->precission = 0;
		if (format[tab->i] == '*')
		{
			tab->precission = va_arg(ap, int);
			tab->i++;
			tab->asterisk++;
		}
		while ((format[tab->i] >= '0' && format[tab->i] <= '9')
			|| format[tab->i] == '*')
		{
			tab->precission = tab->precission * 10 + (format[tab->i] - '0');
			tab->i++;
		}
	}
}

void	flags(const char *format, t_tab *tab, va_list ap)
{
	if (format[tab->i + 1])
	{
		tab->i++;
		while (format[tab->i] == '-' || format[tab->i] == '0')
		{
			if (format[tab->i] == '-')
				tab->minus = 1;
			if (format[tab->i] == '0')
				tab->zero = 1;
			if (tab->zero == 1 && tab->minus == 1)
			{
				tab->minus = 1;
				tab->zero = 0;
			}
			tab->i++;
		}
		flags_asterisk_point(format, tab, ap);
	}
}
