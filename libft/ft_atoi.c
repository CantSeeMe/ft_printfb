/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:31:09 by jye               #+#    #+#             */
/*   Updated: 2016/11/07 14:29:45 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		snt;
	int		n;

	snt = 0;
	n = 1;
	while ((*str >= 0x08 && *str <= 0x0d) || *str == 0x20)
		str++;
	if (*str == '-' || *str == '+')
	{
		n = *str == '-' ? -1 : n;
		str++;
	}
	while (*str && ft_isdigit(*str))
		snt = snt * 10 + (*str++ - 0x30);
	return (snt * n);
}