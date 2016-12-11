/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:41:05 by jye               #+#    #+#             */
/*   Updated: 2016/12/11 17:21:37 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	pp_handler(t_format *c_flag, t_conv *tmp)
{
	int		pad;

	pad = c_flag->pad - tmp->size;
	if (c_flag->flag & 2)
	{
		write(1, tmp->content, tmp->size);
		while (pad-- > 0)
			write(1, &tmp->cpad, 1);
	}
	else
	{
		while (pad-- > 0)
			write(1, &tmp->cpad, 1);
		write(1, tmp->content, tmp->size);
	}
	return (tmp->size > (unsigned int)c_flag->pad ? tmp->size : c_flag->pad);
}

int			f_string(t_format *c_flag, va_list arg)
{
	char		*s;
	t_conv		tmp;

	if (c_flag->length == 4)
		return (f_wstring(c_flag, arg));
	else
	{
		s = va_arg(arg, char *);
		if (!s)
			s = SNULL;
		if ((c_flag->flag & 10) == 10)
			c_flag->flag ^= 8;
		tmp.cpad = c_flag->flag & 8 ? 0x30 : 0x20;
		tmp.size = ft_strlen(s);
		tmp.content = s;
		if (c_flag->flag & 32)
			if (c_flag->precision >= 0 &&
				(unsigned int)c_flag->precision < tmp.size)
				tmp.size = c_flag->precision;
		if (c_flag->pad != 0)
			return (pp_handler(c_flag, &tmp));
		write(1, s, tmp.size);
	}
	return (tmp.size);
}
