/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:49:17 by jye               #+#    #+#             */
/*   Updated: 2016/12/08 22:07:44 by jye              ###   ########.fr       */
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
		write(1, tmp->content, 1);
		while (pad-- > 0)
			write(1, " ", 1);
	}
	else
	{
		while (pad-- > 0)
			write(1, " ", 1);
		write(1, tmp->content, 1);
	}
	return (c_flag->pad);
}

int		f_char(t_format *c_flag, va_list arg)
{
	int		op;
	t_conv	tmp;

	if (c_flag->length == 4)
		return (f_wchar(c_flag, arg));
	else
	{
		op = va_arg(arg, int);
		tmp.content = &op;
		if (c_flag->pad != 0)
			return (pp_handler(c_flag, &tmp));
	}
	write(1, &op, 1);
	return (1);
}
