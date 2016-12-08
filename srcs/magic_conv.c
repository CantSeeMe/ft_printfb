/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/08 20:59:28 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	some_other_shit(t_format *c_flag, va_list arg)
{
	if (c_flag->format == 'O')
		return (0);
	else if (c_flag->format == 'f' || c_flag->format == 'F')
		return (0);
	else if (c_flag->format == 'e' || c_flag->format == 'E')
		return (0);
	else if (c_flag->format == 'a' || c_flag->format == 'A')
		return (0);
	else if (c_flag->format == 'g' || c_flag->format == 'G')
		return (0);
	else
		return (0);
}	

static int	magic_conv_lzj(t_format *c_flag, va_list arg)
{
	if (c_flag->format == 'd' || c_flag->format == 'i')
		return (0);
	else if (c_flag->format == 'x' || c_flag->format == 'X')
		return (0);
	else if (c_flag->format == 'o')
		return (0);
	else if (c_flag->format == 'u')
		return (0);
	return (0);
}

static int	magic_conv_ll(t_format *c_flag, va_list arg)
{
	if (c_flag->format == 'd' || c_flag->format == 'i')
		return (0);
	else if (c_flag->format == 'x' || c_flag->format == 'X')
		return (0);
	else if (c_flag->format == 'o')
		return (0);
	else if (c_flag->format == 'u')
		return (0);
	return (0);
}

static int	magic_conv_nfhh(t_format *c_flag, va_list arg)
{
	if (c_flag->format == 'd' || c_flag->format == 'i')
		return (0);
	else if (c_flag->format == 'x' || c_flag->format == 'X')
		return (0);
	else if (c_flag->format == 'o')
		return (0);
	else if (c_flag->format == 'u')
		return (0);
	return (0);
}

int			magic_conv(t_format *c_flag, va_list arg)
{
	if (c_flag->format == 'c')
		return (f_char(c_flag, arg));
	else if (c_flag->format == 's')
		return (f_string(c_flag, arg));
	else if (c_flag->format == 'C')
		return (f_wchar(c_flag, arg));
	else if (c_flag->format == 'S')
		return (f_wstring(c_flag, arg));
	else if (c_flag->format == 'p')
		return (f_lluhint(c_flag, arg));
	else if (c_flag->format == '%')
		return (0);
	else if (c_flag->format == 'D')
		return (0);
	else if (c_flag->format == 'U')
		return (0);
	else if (c_flag->length & 52)
		return (magic_conv_lzj(c_flag, arg));
	else if (c_flag->length & 8)
		return (magic_conv_ll(c_flag ,arg));
	else if (c_flag->length & 3 || c_flag->length == 0)
		return (magic_conv_nfhh(c_flag ,arg));
	else
		return (some_other_shit(c_flag, arg));
}
