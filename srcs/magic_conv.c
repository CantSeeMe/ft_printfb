/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/11 20:28:33 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	some_other_shit(t_format *c_flag, va_list arg)
{
	(void)arg;
	if (c_flag->format == 'f' || c_flag->format == 'F')
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
/******************************
static int	magic_conv_lzj(t_format *c_flag, va_list arg)
{
	(void)arg;
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
	(void)arg;
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
	(void)arg;
	if (c_flag->format == 'd' || c_flag->format == 'i')
		return (f_sint);
	else if (c_flag->format == 'x' || c_flag->format == 'X')
		return (0);
	else if (c_flag->format == 'o')
		return (0);
	else if (c_flag->format == 'u')
		return (0);
	return (0);
}
******************/
int			magic_conv(t_format *c_flag, va_list arg)
{
	(void)arg;
	if (c_flag->format == 'c')
		return (f_char(c_flag, arg));
	else if (c_flag->format == 's')
		return (f_string(c_flag, arg));
	else if (c_flag->format == 'C')
		return (f_wchar(c_flag, arg));
	else if (c_flag->format == 'S')
		return (f_wstring(c_flag, arg));
	else if (c_flag->format == 'p')
		return (f_pint(c_flag, arg));
	else if (c_flag->format == '%')
		return (f_pcescape(c_flag));
	else if (c_flag->format == 'D' || c_flag->format == 'd' || 
			c_flag->format == 'i')
		return (f_sint(c_flag, arg));
	else if (c_flag->format == 'U' || c_flag->format == 'u')
		return (f_uint(c_flag, arg));
	else if (c_flag->format == 'O' || c_flag->format == 'o')
		return (f_uoint(c_flag, arg));
	else if (c_flag->format == 'X' || c_flag->format == 'x')
		return (f_uxint(c_flag, arg));
	else
		return (some_other_shit(c_flag, arg));
}
