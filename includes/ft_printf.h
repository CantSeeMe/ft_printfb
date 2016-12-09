/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/09 23:01:36 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define FLAG "#-+0 "
# define RESET "#-+0 .lhjz"
# define BASE "0123456789abcdef"
# define LENGTH "lhjz"
# define SNULL "(null)"
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
# define IS_LWORD 0xffffffff00000000
/*
**Typedefs
*/
typedef struct		s_format
{
	int				pad;
	int				precision;
	unsigned char	flag;
	unsigned char	length;
	unsigned char	format;
}					t_format;
typedef struct		s_conv
{
	unsigned long int	size;
	void				*content;
	unsigned char		sign;
	char				cpad;
}					t_conv;
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
** Format handler
*/
void				magic(t_format *c_flag, char **format);
/*
** Link to x format conversion
*/
int					magic_conv(t_format *c_flag, va_list arg);
/*
** Undefined behaviors
*/
int					f_undefined(t_format *c_flag);
/*
** %s %c
** Preicision ignored
** Defined behavior flag '-'
*/
int					f_char(t_format *c_flag, va_list arg);
int					f_string(t_format *c_flag, va_list arg);
/*
** %C %S %ls %lc
** Defined behavior flag '-'
*/
int					f_wchar(t_format *c_flag, va_list arg);
int					f_wstring(t_format *c_flag, va_list arg);
int					w_char(int wchar, char *stack);
/*
** %d %D %ld %lld %lD %i %li %lli
** padding ignored if precision > padding
** precision overwrite flag 0
** Undefined behavior flag '#'
*/
int					f_sint(t_format *c_flag, va_list arg);
/*
** %u %U %lU %llu %lu
** refer to line 152
** padding ignored if precision > padding
** precision overwrite flag 0
*/
int					f_uint(t_format *c_flag, va_list arg);
int					f_luint(t_format *c_flag, va_list arg);
int					f_lluint(t_format *c_flag, va_list arg);
/*
** %o %O %lo %lO %llo
** bit shifting >> 3
** refer to line 152
*/
int					f_uoint(t_format *c_flag, va_list arg);
int					f_luoint(t_format *c_flag, va_list arg);
int					f_lluoint(t_format *c_flag, va_list arg);
/*
** %x %lx %llx %X %lX %llX
** bit shifting >> 4
** %b
** bit shifting >> 1;
** signed flag ignored aka '+' ' '
** --------------------------------
** %p Defined behavior '-'
*/
int					f_uhint(t_format *c_flag, va_list arg);
int					f_luhint(t_format *c_flag, va_list arg);
int					f_lluhint(t_format *c_flag, va_list arg);
/*
** itoa // itoabase
*/
int					f_utoa(unsigned long long int z, char *buff);
int					f_itoa(t_format *c_flag, long long int z, char *buff);
int					f_utoa_base(unsigned long long int z, char *buff, int base);
/*
** %f %F %a %A %g %G %e %E
*/
#endif
