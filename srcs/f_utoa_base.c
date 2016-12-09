/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:00:44 by jye               #+#    #+#             */
/*   Updated: 2016/12/09 15:37:40 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sf_dsz(unsigned long long int z, int base)
{
	int n;

	n = 0;
	while (z)
	{
		z /= base;
		++n;
	}
	return (n);
}

int			f_utoa_base(unsigned long long int z, char *buff, int base)
{
	char	*cbase;
	int		nlen;

	cbase = BASE;
	if (!z)
	{
		*buff = 0x30;
		return (1);
	}
	nlen = sf_dsz(z, base);
	buff += nlen;
	while (z)
	{
		*--buff = cbase[z % base];
		z /= base;
	}
	return (nlen);
}
