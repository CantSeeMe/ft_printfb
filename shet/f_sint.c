/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_sint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:26:46 by jye               #+#    #+#             */
/*   Updated: 2016/12/08 21:17:03 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_sint(t_format *c_flag, va_list arg)
{
	int		conv;
	char	buff[11];
	t_conv	tmp;

	if (c_flag->length & 1)
		conv = 255 & va_arg(arg, int);
	else if (c_flag->length & 2)
		conv = 65535 & va_arg(arg, int);
	else
		conv = va_arg(arg, int);
	tmp.size = f_itoa(conv, buff);
	tmp.content = buff;
	if (c_flag->flag & 28)
		f_handler(c_flag, &tmp)
	if (c_flag->pad)
		return (pp_handler(c_flag, &tmp));
	write(1, buff, tmp.size);
	return (tmp.size);
}
