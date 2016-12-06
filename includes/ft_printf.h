/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/06 21:21:10 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define FLAG "#-+0 "
# define RESET "#-+0 .lhjz"
# define DIGIT "0123456789"
# define UHEX "0123456789ABCDEF"
# define LHEX "0123456789abcdef"
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
# define STACK 0x7fff00000000
# define HEAP 0x7f0000000000
# define RDONLY 0x100000000
# undef INT_MAX
# define INT_MAX 0x7fffffff
# undef INT_MIN
# define INT_MIN 0x80000000
# undef UINT_MAX
# define UINT_MAX 0xffffffff
# undef INT64_MAX
# define INT64_MAX 0x7fffffffffffffffL
# undef INT64_MIN
# define INT64_MIN 0x8000000000000000L
# undef UINT64_MAX
# define UINT64_MAX 0xffffffffffffffffL

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
** Flag handler
*/
int					f_handler(t_format *c_flag, t_conv *conv);
/*
** Precision / Padding handler
*/
int					pp_handler(t_format *c_flag, t_conv *conv);
/*
** Format handler
*/
void				magic(t_format *c_flag, char **format);
/*
** Link to x format conversion
*/
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
** Precision ignored
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
int					f_lsint(t_format *c_flag, va_list arg);
int					f_llsint(t_format *c_flag, va_list arg);
int					f_itoa(long long int nb, char *buff, int int_min);
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
** %f %F %a %A %g %G %e %E
*/
#endif
