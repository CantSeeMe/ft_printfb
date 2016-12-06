/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/06 21:30:45 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	magic_print(char **format)
{
	char	*f;
	int		a;

	f = *format;
	while (*f != 0x25 && *f)
		write(1, f++, 1);
	a = f - *format;
	*format = f;
	return (a);
}

int			ft_printf(const char *format, ...)
{
	int			nb;
	va_list		arg;
	t_format	c_da;

	if (format == NULL)
		return (0);
	va_start(arg, format);
	nb = 0;
	while (*format)
	{
		if (*format == 0x25)
		{
			magic(&c_da, (char **)&format);
			nb += magic_conv(&c_da, arg);
		}
		nb += magic_print((char **)&format);
	}
	va_end(arg);
	return (nb);
}
