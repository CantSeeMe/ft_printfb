/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 00:00:00 by jye               #+#    #+#             */
/*   Updated: 2016/12/13 16:06:21 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# define FLAG "#-+0 "
# define RESET "#-+0 .*lhjz"
# define BASE "0123456789abcdef"
# define LENGTH "lhjz"
# define SNULL "(null)"
# define BLACK "\x1B[30m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m"
# define CRESET "\x1B[0m"
# define BUFF_SIZE 512
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
typedef struct		s_buffer
{
	void	(*w)(struct s_buffer *);
	int		z;
	int		i;
	char	buff[BUFF_SIZE];
}					t_buffer;
typedef struct		s_format
{
	t_buffer		buffer;
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
void				magic(t_format *c_flag, char **format, va_list arg);
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
/*
** %o %O %lo %lO %llo
** bit shifting >> 3
** refer to line 152
*/
int					f_uoint(t_format *c_flag, va_list arg);
/*
** %x %lx %llx %X %lX %llX
** bit shifting >> 4
** %b
** bit shifting >> 1;
** signed flag ignored aka '+' ' '
** --------------------------------
** %p Defined behavior '-'
*/
int					f_uxint(t_format *c_flag, va_list arg);
int					f_pint(t_format *c_flag, va_list arg);
/*
** %%
*/
int					f_undefined(t_format *c_flag);
/*
** itoa // itoabase
*/
int					f_utoa(t_format *c_flag, unsigned long long int z,
					char *buff);
int					f_itoa(t_format *c_flag, long long int z,
					char *buff);
int					f_utox(t_format *c_flag, unsigned long long int z,
					char *buff);
int					f_utoo(t_format *c_flag, unsigned long long int z,
					char *buff);
int					f_utob(t_format *c_flag, unsigned long long int z,
					char *buff);
/*
** %f %F %a %A %g %G %e %E
*/
/*
**etc function
*/
char				*ft_strchrnul(const char *s, unsigned char c);
void				print_padding(int lpad, char cpad);
void				print_precision(int lprec);
#endif
