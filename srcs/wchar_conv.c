/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 19:53:40 by jye               #+#    #+#             */
/*   Updated: 2016/12/06 21:01:05 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	wchar_conv(char *bstr, const int *qstr)
{
	unsigned long int offset;

	offset = 0;
	while (*qstr)
		offset += w_char(*qstr++, bstr + offset);
	return (offset);
}
