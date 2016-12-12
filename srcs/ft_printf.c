/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/12 19:35:44 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	magic_print(char **format)
{
	char	*f;
	char	*s_modulo;
	char	*s_bracket;
	char	*actual;
	int		to_w;

	f = *format;
	s_modulo = ft_strchrnul(f, 0x25);
	s_bracket = ft_memchr(f, 0x7b, s_modulo - f);
	actual = s_modulo > s_bracket ? s_modulo : s_bracket;
	to_w = actual - f;
	write(1, f, to_w);
	*format += to_w;
	return (to_w);
}

static int	is_color(char *buff)
{
	char	bool__;

	bool__ = 0;
	if (!ft_strcmp(buff, "{black}") && (bool__ = 1))
		write(1, BLACK, 5);
	else if (!ft_strcmp(buff, "{red}") && (bool__ = 1))
		write(1, RED, 5);
	else if (!ft_strcmp(buff, "{green}") && (bool__ = 1))
		write(1, GREEN, 5);
	else if (!ft_strcmp(buff, "{yellow}") && (bool__ = 1))
		write(1, YELLOW, 5);
	else if (!ft_strcmp(buff, "{blue}") && (bool__ = 1))
		write(1, BLUE, 5);
	else if (!ft_strcmp(buff, "{magenta}") && (bool__ = 1))
		write(1, MAGENTA, 5);
	else if (!ft_strcmp(buff, "{cyan}") && (bool__ = 1))
		write(1, CYAN, 5);
	else if (!ft_strcmp(buff, "{white}") && (bool__ = 1))
		write(1, WHITE, 5);
	else if (!ft_strcmp(buff, "{eos}") && (bool__ = 1))
		write(1, CRESET, 4);
	return (bool__);
}

static int	is_modulo(char *buff)
{
	char *a;

	a = buff;
	while (*a != 0x25 && *a)
		++a;
	return (a - buff);
}

static int	magic_color(char **color)
{
	char	*f;
	char	buff[11];
	int		i;

	f = *color;
	i = -1;
	while (++i < 10 && f[i] && f[i] != 0x7d)
		buff[i] = f[i];
	if (f[i] == 0x7d)
		buff[i++] = 0x7d;
	buff[i] = 0;
	if (is_color(buff))
	{
		*color += i;
		return (0);
	}
	else
	{
		i = is_modulo(buff);
		write(1, buff, i);
		*color += i;
		return (i);
	}
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
			format += 1;
			magic(&c_da, (char **)&format);
			nb += magic_conv(&c_da, arg);
		}
		else if (*format == 0x7b)
			nb += magic_color((char **)&format);
		nb += magic_print((char **)&format);
	}
	va_end(arg);
	return (nb);
}
