/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizacion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:50:38 by jye               #+#    #+#             */
/*   Updated: 2016/12/13 17:24:24 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void		print_padding(int lpad, char cpad, struct s_buffer *buffer)
{
	if (lpad + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	ft_memset(buffer->buff + buffer->i, cpad, lpad);
	buffer->i += lpad;
	buffer->z += lpad;
}

void		print_precision(int lprec, struct s_buffer *buffer)
{
	if (lprec + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	ft_memset(buffer->buff + buffer->i, 0x30, lprec);
	buffer->i += lprec;
	buffer->z += lprec;
}

void		write_t_buffer__(struct s_buffer *buffer, void *s, unsigned long n)
{
	if (n + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	ft_memcpy(buffer->buff + buffer->i, s, n);
	buffer->i += n;
	buffer->z += n;
}

void		init_t_buffer__(t_buffer *buffer)
{
	buffer->z = 0;
	buffer->i = 0;
	buffer->w = &write_t_buffer__;
}
