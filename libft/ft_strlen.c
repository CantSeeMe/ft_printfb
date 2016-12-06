/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/05 17:47:44 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned int	*magic;
	char			*ab;

	ab = (char *)str;
	while ((unsigned long)ab & (sizeof(unsigned int) - 1))
		if (*ab++ == 0)
			return (ab - str - 1);
	magic = (unsigned int *)ab;
	while (1)
	{
		if ((*magic - 0x1010101) & 0x80808080)
		{
			ab = (char *)magic;
			if (ab[0] == 0)
				return (ab - str);
			if (ab[1] == 0)
				return (ab - str + 1);
			if (ab[2] == 0)
				return (ab - str + 2);
			if (ab[3] == 0)
				return (ab - str + 3);
		}
		++magic;
	}
}
