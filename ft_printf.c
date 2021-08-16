/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgomez-b <lgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 09:36:11 by lgomez-b          #+#    #+#             */
/*   Updated: 2020/03/09 10:20:24 by lgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void		ft_pft(const char *format, t_tab *tab)
{
	if (format[tab->i] == 'd' || format[tab->i] == 'i')
	{
		tab->type = 'd';
		tab->nb = va_arg(tab->ap, int);
		integers(tab);
	}
	else if (format[tab->i] == 'u')
	{
		tab->type = 'u';
		tab->nb = va_arg(tab->ap, unsigned int);
		integers(tab);
	}
	else if (format[tab->i] == 'x' || format[tab->i] == 'X')
	{
		if (format[tab->i] == 'x')
			tab->type = 'x';
		else
			tab->type = 'X';
		tab->nb = va_arg(tab->ap, unsigned int);
		hexadecimal(tab);
	}
}

void		ft_pft2(const char *format, t_tab *tab)
{
	if (format[tab->i] == 's')
	{
		tab->cnt_length = 0;
		tab->type = 's';
		tab->str = va_arg(tab->ap, char*);
		if (tab->str == NULL)
			tab->str = "(null)";
		strings(tab);
		tab->cnt_length = 0;
	}
	else if (format[tab->i] == 'c')
	{
		tab->c = va_arg(tab->ap, int);
		chars(tab);
	}
	else if (format[tab->i] == 'p')
	{
		tab->type = 'p';
		tab->nb = va_arg(tab->ap, long long int);
		if (tab->nb == '\0')
			tab->nb = 0;
		pointers(tab);
	}
	else if (format[tab->i] == '%')
		pcnt(tab);
}

void		elses(const char *format, t_tab *tab)
{
	tab->c = format[tab->i];
	ft_putchar(tab);
	tab->i++;
}

int			ft_printf(const char *format, ...)
{
	t_tab	tab;

	va_start(tab.ap, format);
	initflags(&tab);
	while (format[tab.i] != '\0')
	{
		if (format[tab.i] == '%')
		{
			reiniflags(&tab);
			flags(format, &tab, tab.ap);
			if (format[tab.i] == 'd' || format[tab.i] == 'i' ||
			format[tab.i] == 'u' || format[tab.i] == 'x' ||
			format[tab.i] == 'X')
				ft_pft(format, &tab);
			else if (format[tab.i] == 's' || format[tab.i] == 'p' ||
			format[tab.i] == '%' || format[tab.i] == 'c')
				ft_pft2(format, &tab);
			if (format[tab.i] != '\0')
				tab.i++;
		}
		else
			elses(format, &tab);
		reiniflags(&tab);
	}
	return (tab.cnt_chars);
}
