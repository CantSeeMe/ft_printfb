#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jye <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 15:55:18 by jye               #+#    #+#              #
#    Updated: 2016/12/09 15:56:50 by jye              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Compiler

CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror -g
LAFLAG	=	-L libft -lft
PAFLAG	=	-L . -lftprintf

# Directories

SDIR	=	srcs
ODIR	=	obj
HDIR	=	includes
LHDIR	=	libft/includes
LDIR	=	libft

# Files

SRC		=	f_char.c f_string.c f_wstring.c wchar_conv.c f_wchar.c w_char.c \
			magic_conv.c magic.c ft_printf.c
OBJ		=	$(addprefix $(ODIR)/, $(addsuffix .o,$(basename $(SRC))))
LIBFT	=	libft/libft.a

# Lib name

NAME	=	libftprintf.a

all			:	$(NAME)

.PHONY		:	all clean fclean re

clean		:
	@make -C $(LDIR) clean
	/bin/rm -rf $(ODIR)

fclean		:	clean
	/bin/rm -rf $(LDIR)/libft.a
	/bin/rm -rf $(NAME)

re			:	fclean all

$(NAME)		:	$(OBJ)
	ar -rcs $(ODIR)/$@ $(OBJ) 
	libtool -static -o $@ $(ODIR)/$@ $(LIBFT)

$(ODIR)/%.o	:	$(SDIR)/%.c $(LIBFT)
	@/bin/mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CFLAG) -I$(HDIR) -I$(LHDIR)

$(LIBFT)	:
	@make -C $(LDIR)

main		:
	$(CC) main.c $(PAFLAG) -I$(LHDIR) -I$(HDIR)