/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_wchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:45:59 by jye               #+#    #+#             */
/*   Updated: 2016/12/08 21:06:19 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int			f_wchar(t_format *c_flag, va_list arg)
{
	int		wchar;
	char	a[5];
	t_conv	tmp;

	wchar = va_arg(arg, int);
	tmp.size = w_char(wchar, a);
	tmp.content = a;
	if (c_flag->pad != 0)
		return (pp_handler(c_flag, &tmp));
	write(1, a, tmp.size);
	return (tmp.size);
}
