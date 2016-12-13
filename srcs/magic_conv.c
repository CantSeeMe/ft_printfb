/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/13 17:23:47 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	some_other_shit(t_format *c_flag, va_list arg)
{
	(void)arg;
#if 0
	if (c_flag->format == 'f' || c_flag->format == 'F')
		return (0);
	else if (c_flag->format == 'e' || c_flag->format == 'E')
		return (0);
	else if (c_flag->format == 'a' || c_flag->format == 'A')
		return (0);
	else if (c_flag->format == 'g' || c_flag->format == 'G')
		return (0);
	else
#endif
		f_undefined(c_flag);
}

void		magic_conv(t_format *c_flag, va_list arg)
{
	(void)arg;
	if (c_flag->format == 'c')
		f_char(c_flag, arg);
	else if (c_flag->format == 's')
		f_string(c_flag, arg);
	else if (c_flag->format == 'C')
		f_wchar(c_flag, arg);
	else if (c_flag->format == 'S')
		f_wstring(c_flag, arg);
	else if (c_flag->format == 'p')
		f_pint(c_flag, arg);
#if 0
	else if (c_flag->format == 'n')
#endif
	else if (c_flag->format == 'D' || c_flag->format == 'd' ||
			c_flag->format == 'i')
		f_sint(c_flag, arg);
	else if (c_flag->format == 'U' || c_flag->format == 'u')
		f_uint(c_flag, arg);
	else if (c_flag->format == 'O' || c_flag->format == 'o')
		f_uoint(c_flag, arg);
	else if (c_flag->format == 'X' || c_flag->format == 'x')
		f_uxint(c_flag, arg);
	else
		some_other_shit(c_flag, arg);
}
