/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/06 15:20:10 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define FLAG "#-+0"
# define BYTE 0x6868
# define WORD 0x68
# define DWORD 0x6c
# define QWORD 0x6c6c
# define MAX 0x6a
# define SIZE 0x7a
# define INF32 0x7f800000
# define INF64 0x7ff0000000000000L
# define NAN32 0x7fc00000
# define NAN64 0x7ff8000000000000L
# define ADDRESS 0x7fff00000000
# define INT_MAX 0x7fffffff
# define INT_MIN 0x80000000
# define UINT_MAX 0xffffffff
# define INT64_MAX 0x7fffffffffffffffL
# define INT64_MIN 0x8000000000000000L
# define UINT64_MAX 0xffffffffffffffffL
/*
**printf %conversion, #-+0flag, .precision, type conversion
*/

/*
**Typedefs
*/
typedef struct	s_format
{
	int				pad;
	int				precision;
	unsigned char	flag;
	unsigned char	length;
	unsigned char	format;
}				t_format;
/*
**Float typedef
*/
typedef struct		s_float32
{
	unsigned int		sign:1;
	unsigned int		exponent:8;
	unsigned int		mantissa:23;
}					t_float32;
/*
**Double typedef
*/
typedef struct		s_double64
{
	unsigned long long int	sign:1;
	unsigned long long int	exponent:11;
	unsigned long long int	mantissa:52;
}					t_double64;
/*
**Function prototype printf
*/
int					ft_printf(const char *format, ...);
/*
**Format Part
*/
void				magic(t_format *c_flag, char **format);
int					magic_conv(t_format *c_flag, va_list arg);
/*
**Flag Handler
*/
/*
**Precision / Padding handler
*/
/*
**Format Handler
*/
/*
**Char / CharString Format %s %c
*/
int					f_char(t_format *c_flag, va_list arg);
int					f_string(t_format *c_flag, va_list arg);
/*
**wChar / wCharString Format %C %S %ls %lc
*/
int					f_wchar(t_format *c_flag, va_list arg);
int					f_wstring(t_format *c_flag, va_list arg);
int					w_char(int wchar, char *stack);
unsigned long int	ft_wstrlen(const int *wchar);
/*
**Integer Type %d %D %ld %lld %lD %i %li %lli
*/
int					f_sint(t_format *c_flag, va_list arg);
int					f_lsint(t_format *c_flag, va_list arg);
int					f_llsint(t_format *c_flag, va_list arg);
int					f_itoa(long long int nb, char *buff, int int_min);
/*
** %u %U %lU %llu %lu
*/
int					f_uint(t_format *c_flag, va_list arg);
int					f_luint(t_format *c_flag, va_list arg);
int					f_lluint(t_format *c_flag, va_list arg);
/*
** %o %O %lo %lO %llo
*/
int					f_uoint(t_format *c_flag, va_list arg);
int					f_luoint(t_format *c_flag, va_list arg);
int					f_lluoint(t_format *c_flag, va_list arg);
/*
** %x %lx %llx %X %lX %llX
*/
int					f_uhint(t_format *c_flag, va_list arg);
int					f_luhint(t_format *c_flag, va_list arg);
int					f_lluhint(t_format *c_flag, va_list arg);
/*
**Memory adress type %p (unsigned long long int) 6 bytes long
*/

/*
**Float type Conversion
*/
#endif
