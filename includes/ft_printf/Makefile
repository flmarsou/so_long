# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 15:43:02 by flmarsou          #+#    #+#              #
#    Updated: 2024/06/06 14:58:58 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libftprintf.a

SRC = ./src/ft_printf.c \
	  ./src/ft_putchr.c \
	  ./src/ft_puthex.c \
	  ./src/ft_putnbr.c \
	  ./src/ft_putptr.c \
	  ./src/ft_putstr.c \
	  ./src/ft_putuni.c

OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all:		${LIB}

%.o:		%.c
		@${CC} ${CFLAGS} -c $? -o $@

${LIB}:		${OBJ}
		@ar rcs $@ $?

clean:
		@${RM} ${OBJ}

fclean:		clean
		@${RM} ${LIB}

re:			fclean all

.PHONY: all clean fclean re
