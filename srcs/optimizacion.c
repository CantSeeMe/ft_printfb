/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizacion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 20:50:38 by jye               #+#    #+#             */
/*   Updated: 2016/12/13 20:00:59 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

void		print_padding(int lpad, char cpad, struct s_buffer *buffer)
{
//	char	*padd;

	if (lpad + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	if (lpad > BUFF_SIZE)
	{
		ft_memset(buffer->buff, cpad, BUFF_SIZE);
		while (lpad >= BUFF_SIZE)
		{
			write(1, buffer->buff, BUFF_SIZE);
			buffer->z += BUFF_SIZE;
			lpad -= BUFF_SIZE;
		}
		write(1, buffer->buff, lpad);
		buffer->z += lpad;
	}
	else
	{
		ft_memset(buffer->buff + buffer->i, cpad, lpad);
		buffer->i += lpad;
		buffer->z += lpad;
	}
}

void		print_precision(int lprec, struct s_buffer *buffer)
{
//	char	*prec;

	if (lprec + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	if (lprec > BUFF_SIZE)
	{
		ft_memset(buffer->buff, 0x30, BUFF_SIZE);
		while (lprec >= BUFF_SIZE)
		{
			write(1, buffer->buff, BUFF_SIZE);
			buffer->z += BUFF_SIZE;
			lprec -= BUFF_SIZE;
		}
		write(1, buffer->buff, lprec);
		buffer->z += lprec;
	}
	else
	{
		ft_memset(buffer->buff + buffer->i, 0x30, lprec);
		buffer->i += lprec;
		buffer->z += lprec;
	}
}

void		write_t_buffer__(struct s_buffer *buffer, void *s, unsigned long n)
{
	char *buff;

	if (n + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	if (n > BUFF_SIZE)
	{
		if (!(buff = (char *)malloc(sizeof(char) * n)))
			exit(EXIT_FAILURE);
		ft_memcpy(buff, s, n);
		write(1, buff, n);
		buffer->z += n;
		free(buff);
	}
	else
	{
		ft_memcpy(buffer->buff + buffer->i, s, n);
		buffer->i += n;
		buffer->z += n;
	}
}

void		init_t_buffer__(t_buffer *buffer)
{
	buffer->z = 0;
	buffer->i = 0;
	buffer->w = &write_t_buffer__;
}
