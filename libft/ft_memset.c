/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:47:40 by jye               #+#    #+#             */
/*   Updated: 2016/12/05 21:30:35 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int c, size_t mlen)
{
	unsigned long long int	bmagic;
	unsigned long long int	*magic;
	unsigned char			*shit;

	if (mlen >= 8)
	{
		bmagic = c & 255;
		bmagic = (bmagic << 8) | bmagic;
		bmagic = (bmagic << 16) | bmagic;
		bmagic = ((bmagic << 16) << 16) | bmagic;
		magic = (unsigned long long int *)mem;
		while (mlen >= 8)
		{
			*magic++ = bmagic;
			mlen -= 8;
		}
	}
	shit = (unsigned char *)mem;
	while (mlen)
		shit[--mlen] = c & 255;
	return (mem);
}
