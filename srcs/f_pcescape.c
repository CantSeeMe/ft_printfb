/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pcescape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 20:32:26 by jye               #+#    #+#             */
/*   Updated: 2016/12/11 22:30:07 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	pp_handler(t_format *c_flag, t_conv *tmp)
{
	int		pad;

	pad = c_flag->pad - tmp->size;
	if (c_flag->flag & 2)
	{
		write(1, tmp->content, 1);
		while (pad-- > 0)
			write(1, &tmp->cpad, 1);
	}
	else
	{
		while (pad-- > 0)
			write(1, &tmp->cpad, 1);
		write(1, tmp->content, 1);
	}
	return (c_flag->pad);
}

int			f_pcescape(t_format *c_flag)
{
	t_conv	tmp;
	
	if ((c_flag->flag & 10) == 10)
		c_flag->flag ^= 8;
	tmp.cpad = c_flag->flag & 8 ? 0x30 : 0x20;
	tmp.size = 1;
	tmp.content = PC;
	if (c_flag->pad != 0)
		return (pp_handler(c_flag, &tmp));
	write(1, PC, 1);
	return (1);
}
