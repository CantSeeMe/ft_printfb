/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_itoa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:06:42 by jye               #+#    #+#             */
/*   Updated: 2016/12/09 15:38:01 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sf_dsz(long long int z)
{
	int n;

	n = 0;
	while (z)
	{
		z /= 10;
		++n;
	}
	return (n);
}

static int	not_enuff_room(char *buff)
{
	*buff = 0x30;
	return (1);
}

int			f_itoa(long long int z, char *buff)
{
	int		nlen;

	if (!z)
		return (not_enuff_room(buff));
	nlen = sf_dsz(z);
	if (z < 0 && (nlen += 1))
	{
		buff += nlen;
		while (z)
		{
			*--buff = 0x30 - (z % 10);
			z /= 10;
		}
		*--buff = '-';
	}
	else
	{
		buff += nlen;
		while (z)
		{
			*--buff = 0x30 + (z % 10);
			z /= 10;
		}
	}
	return (nlen);
}
