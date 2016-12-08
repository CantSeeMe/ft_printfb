/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_wchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:45:59 by jye               #+#    #+#             */
/*   Updated: 2016/12/08 21:05:09 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static unsigned long int	ft_wstrlen(const int *str)
{
	register const int *cp;

	if (str == NULL)
		return (0);
	cp = str;
	while (*cp)
		++cp;
	return (cp - str);
}

static unsigned long int	wchar_conv(char *bstr, const int *qstr)
{
	unsigned long int offset;

	if (bstr == NULL)
		return (6);
	offset = 0;
	while (*qstr)
		offset += w_char(*qstr++, bstr + offset);
	return (offset);
}

int							f_wstring(t_format *c_flag, va_list arg)
{
	int					*wchar;
	char				*a;
	t_conv				tmp;
	unsigned long int	w_len;

	wchar = va_arg(arg, int *);
	a = NULL;
	if (wchar == NULL)
		a = SNULL;
	w_len = ft_wstrlen(wchar);
	if (a == NULL)
		if ((a = ft_strnew(w_len * 4)) == NULL)
			exit(EXIT_FAILURE);
	tmp.size = wchar_conv(a, wchar);
	tmp.content = a;
	if (c_flag->pad != 0)
		return (pp_handler(c_flag, &tmp));
	write(1, a, tmp.size);
	free(a);
	return (tmp.size);
}
