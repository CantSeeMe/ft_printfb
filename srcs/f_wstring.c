/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_wchar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:45:59 by jye               #+#    #+#             */
/*   Updated: 2018/12/19 04:18:31 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static void	wchar_conv(t_format *c_flag, const int *qstr)
{
	char				bstr[8];
	int					prec;
	int					word;

	if (c_flag->flag & 32)
	{
		prec = c_flag->precision;
		while (*qstr)
		{
			word = w_char(*qstr++, bstr);
			prec -= word;
			if (prec < 0)
				return ;
			write_buf(bstr, word);
		}
	}
	else
		while (*qstr)
		{
			word = w_char(*qstr++, bstr);
			write_buf(bstr, word);
		}
}

static void	pp_handler(t_format *c_flag, t_conv *tmp)
{
	int		pad;

	pad = c_flag->pad - tmp->size;
	if (c_flag->flag & 2)
	{
		wchar_conv(c_flag, tmp->content);
		if (pad > 0)
			print_pp(pad, tmp->cpad);
	}
	else
	{
		if (pad > 0)
			print_pp(pad, tmp->cpad);
		wchar_conv(c_flag, tmp->content);
	}
}

void		f_wstring(t_format *c_flag, va_list arg)
{
	int					*wchar;
	t_conv				tmp;

	wchar = va_arg(arg, int *);
	if ((c_flag->flag & 10) == 10)
		c_flag->flag ^= 8;
	tmp.cpad = c_flag->flag & 8 ? 0x30 : 0x20;
	tmp.content = wchar;
	if (c_flag->pad != 0)
		pp_handler(c_flag, &tmp);
	else
		wchar_conv(c_flag, wchar);
}
