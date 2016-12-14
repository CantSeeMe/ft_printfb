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
	char	*padd;

	if (lpad + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	if (lpad > BUFF_SIZE)
	{
		if (!(padd = ft_memallocset(cpad, lpad)))
			exit(EXIT_FAILURE);
		write(1, padd, lpad);
		buffer->z += lpad;
		free(padd);
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
	char	*prec;

	if (lprec + buffer->i > BUFF_SIZE)
	{
		write(1, buffer->buff, buffer->i);
		buffer->i = 0;
	}
	if (lprec > BUFF_SIZE)
	{
		if (!(prec = ft_memallocset(0x30, lprec)))
			exit(EXIT_FAILURE);
		write(1, prec, lprec);
		buffer->z += lprec;
		free(prec);
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
	if (n > BUFFER_SIZE)
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
