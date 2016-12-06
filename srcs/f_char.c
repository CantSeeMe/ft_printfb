/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:49:17 by jye               #+#    #+#             */
/*   Updated: 2016/12/06 21:14:24 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		f_char(t_format *c_flag, va_list arg)
{
	int		op;
	t_conv	tmp;

	if (c_flag->length == 4)
		return (f_wchar(c_flag, arg));
	else
	{
		op = va_arg(arg, int);
		tmp.size = 1;
		tmp.content = &op;
		if (c_flag->flag & 1)
			return (flag_handler(c_flag, &tmp));
		if (c_flag->pad != 0)
			return (pp_handler(c_flag, arg, &tmp));
		write(1, &op, 1);
	}
	return (1);
}
