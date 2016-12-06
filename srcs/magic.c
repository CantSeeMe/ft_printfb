/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:03:45 by jye               #+#    #+#             */
/*   Updated: 2016/12/05 16:36:23 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	f_flag(char **format)
{
	int		i_flag;
	char	*f;
	char	*flag;

	f = *format;
	flag = FLAG;
	i_flag = 0;
	while (*f == flag[0] || *f == flag[1] || *f == flag[2] || *f == flag[3])
	{
		if (*f == flag[0])
			i_flag |= 1;
		else if (*f == flag[1])
			i_flag |= 2;
		else if (*f == flag[2])
			i_flag |= 4;
		else if (*f == flag[3])
			i_flag |= 8;
		++f;
	}
	*format = f;
	return (i_flag);
}

static int	get_int(char **format)
{
	char			*f;
	register int	nb;

	if (**format == 0x2e)
		return (0);
	f = *format;
	nb = 0;
	while (*f >= 0x30 && *f <= 0x39)
		nb = nb * 10 + (*f++ - 0x30);
	*format = f;
	return (nb);
}

static int	f_length(char **format)
{
	register unsigned short *s;

	s = (unsigned short *)*format;
	if (*s == BYTE && (*format += 2))
		return (1);
	else if ((*s & 0xff) == WORD && (*format += 1))
		return (2);
	else if (*s == QWORD && (*format += 2))
		return (8);
	else if ((*s & 0xff) == DWORD && (*format += 1))
		return (4);
	else if ((*s & 0xff) == MAX && (*format += 1))
		return (7);
	else if ((*s & 0xff) == SIZE && (*format += 1))
		return (15);
	return (0);
}

void		magic(t_format *c_flag, char **format)
{
	c_flag->flag = f_flag(format);
	c_flag->pad = get_int(format);
	if (**format == 0x2e)
	{
		++*format;
		c_flag->precision = get_int(format);
	}
	else
		c_flag->precision = 0;
	c_flag->length = f_length(format);
	c_flag->format = *(*format)++;
}
