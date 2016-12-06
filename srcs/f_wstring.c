/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_wchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:45:59 by jye               #+#    #+#             */
/*   Updated: 2016/12/06 15:06:26 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int	wchar_conv(char *bstr, const int *qstr)
{
	unsigned long int	offset;

	offset = 0;
	while (*qstr)
	{
		offset += w_char(*qstr, bstr + offset);
		++qstr;
	}
	return (offset);
}

int			f_wstring(t_format *c_flag, va_list arg)
{
	int				*wchar;
	char			*a;
	unsigned int	w_len;
	unsigned int	len;

	if (c_flag->flag)
		return (flag_handler(c_flag, arg));
	if (c_flag->pad || c_flag->precision)
		return (pp_handler(c_flag, arg));
	wchar = va_arg(arg, int *);
	if (wchar == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	w_len = ft_wstrlen(wchar);
	if ((a = ft_strnew(w_len * 4)) == NULL)
		return (-1);
	len = wchar_conv(a, wchar);
	write(1, a, len);
	free(a);
	return (len);
}
