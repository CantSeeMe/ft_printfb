/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:26:46 by jye               #+#    #+#             */
/*   Updated: 2016/12/12 21:29:13 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void					handler__(t_format *c_flag, t_conv *tmp,
								int lpad, int lprec)
{
	if (c_flag->flag & 2)
	{
		write(1, "0x", 2);
		if (lprec > 0)
			print_precision(lprec);
		write(1, tmp->content, tmp->size);
		if (lpad > 0)
			print_padding(lpad, tmp->cpad);
	}
	else
	{
		if (tmp->cpad == 0x30)
			write(1, "0x", 2);
		if (lpad > 0)
			print_padding(lpad, tmp->cpad);
		if (tmp->cpad != 0x30)
			write(1, "0x", 2);
		if (lprec > 0)
			print_precision(lprec);
		write(1, tmp->content, tmp->size);
	}
}

static int					pp_handler__(t_format *c_flag, t_conv *tmp)
{
	int		lpad;
	int		lprec;
	int		ret;

	lpad = -2;
	lprec = 0;
	tmp->cpad = c_flag->flag & 8 ? 0x30 : 0x20;
	if (c_flag->flag & 32)
		lprec = c_flag->precision - tmp->size;
	if (lprec > 0)
		lpad += (c_flag->pad - (lprec + tmp->size));
	else
		lpad += (c_flag->pad - tmp->size);
	if (c_flag->flag & 1)
		lpad -= 2;
	handler__(c_flag, tmp, lpad, lprec);
	tmp->size += 2;
	c_flag->precision += 2;
	ret = c_flag->precision > c_flag->pad ? c_flag->precision : c_flag->pad;
	ret = ret > (int)tmp->size ? ret : tmp->size;
	return (ret);
}

int							f_pint(t_format *c_flag, va_list arg)
{
	unsigned long long	conv;
	char				buff[17];
	t_conv				tmp;

	if (c_flag->flag & 28)
	{
		if ((c_flag->flag & 10) == 10)
			c_flag->flag ^= 8;
		else if (c_flag->flag & 32)
			c_flag->flag &= 0xf7;
	}
	conv = va_arg(arg, unsigned long long);
	tmp.size = f_utox(c_flag, conv, buff);
	tmp.content = buff;
	tmp.cpad = c_flag->flag & 8 ? 0x30 : 0x20;
	if (c_flag->pad || c_flag->precision)
		return (pp_handler__(c_flag, &tmp));
	write(1, "0x", 2);
	write(1, buff, tmp.size);
	return (tmp.size + 2);
}
