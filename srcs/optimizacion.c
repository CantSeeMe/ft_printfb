/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizacion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:50:38 by jye               #+#    #+#             */
/*   Updated: 2016/12/13 16:05:10 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void		print_padding(int lpad, char cpad)
{
	char	buff[lpad];

	ft_memset(buff, cpad, lpad);
	write(1, buff, lpad);
}

void		print_precision(int lprec)
{
	char	buff[lprec];

	ft_memset(buff, 0x30, lprec);
	write(1, buff, lprec);
}

void		write_t_buffer__(struct s_buffer *buffer, void *s, unsigned long n);
{
	if (n + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, i);
		buffer->i = 0;
	}
	ft_memcpy(buffer->buffer + buffer->i, s, n);
	buffer->i += n;
}

void		init_t_buffer__(t_buffer *buffer)
{
	buffer->z = 0;
	buffer->i = 0;
	buffer->p = &write_t_buffer__;
}
