# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 12:59:58 by flmarsou          #+#    #+#              #
#    Updated: 2024/07/17 15:15:10 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	so_long

# Files
SRC			=	./src/main.c \

SRC_UTILS	=	./src/utils/ft_putstr.c \
				./src/utils/ft_puterr.c \
				./src/utils/ft_strlen.c \
				./src/utils/ft_strcmp.c \

SRC_MAP		=	./src/map/init_map.c \

SOURCES		=	${SRC} ${SRC_UTILS} ${SRC_MAP}
OBJECTS		=	${SOURCES:.c=.o}

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -g3 -fsanitize=address
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} ${CFLAGS} ${OBJECTS} ${LIBS} -o ${EXE}

%.o:		%.c
			@${CC} ${CFLAGS} -c $? -o $@

clean:
			@${RM} ${OBJECTS}

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
