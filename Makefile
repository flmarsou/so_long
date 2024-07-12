# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 09:44:05 by flmarsou          #+#    #+#              #
#    Updated: 2024/07/12 14:07:13 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = so_long

# Files
SRC		=		./src/main.c \

SOURCES = 		${SRC}
OBJECTS = 		${SOURCES:.c=.o}

# Libraries
FT_PRINTF =		./includes/ft_printf
MINILIBX =		./includes/minilibx-linux

# Variables
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address
RM		= rm -f

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
		@${MAKE} -C ${FT_PRINTF} > /dev/null
		@${MAKE} -C ${MINILIBX}
		@${CC} ${CFLAGS} ${OBJECTS} ${FT_PRINTF}/libftprintf.a -o ${EXE}

%.o:		%.c
		@${CC} ${CFLAGS} -c $? -o $@

clean:
		@${MAKE} -C ${FT_PRINTF} clean > /dev/null
		@${MAKE} -C ${MINILIBX} clean
		@${RM} ${OBJECTS}

fclean:		clean
		@${MAKE} -C ${FT_PRINTF} fclean > /dev/null
		@${RM} ${OBJECTS} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
