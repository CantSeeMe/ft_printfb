/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/06 21:20:30 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		magic_conv(t_format *c_flag, va_list arg)
{
	if (c_flag->format == 'c')
		return (f_char(c_flag, arg));
	else if (c_flag->format == 's')
		return (f_string(c_flag, arg));
	else if (c_flag->format == 'C')
		return (f_wchar(c_flag, arg));
	else if (c_flag->format == 'S')
		return (f_wstring(c_flag, arg));
	else
		return (f_undefined(c_flag));
}
