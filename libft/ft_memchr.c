/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:57:12 by jye               #+#    #+#             */
/*   Updated: 2016/11/04 19:56:01 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, const unsigned char c, size_t n)
{
	unsigned char *a;

	a = (unsigned char *)str;
	while (n--)
	{
		if (c != *a)
			++a;
		else
			return (a);
	}
	return (NULL);
}
