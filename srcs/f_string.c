/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:41:05 by jye               #+#    #+#             */
/*   Updated: 2016/12/08 21:05:55 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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
		tmp.size = ft_strlen(s);
		tmp.content = s;
		if (c_flag->pad != 0)
			return (pp_handler(c_flag, &tmp));
		write(1, s, tmp.size);
	}
	return (tmp.size);
}
