# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 12:59:58 by flmarsou          #+#    #+#              #
#    Updated: 2024/07/24 08:37:28 by flmarsou         ###   ########.fr        #
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
				./src/utils/ft_strchr.c \
				./src/utils/ft_strdup.c \
				./src/utils/ft_strjoin.c \

SRC_MAP		=	./src/map/init_map.c \
				./src/map/read_map.c \
				./src/map/parse_map.c \

SOURCES		=	${SRC} ${SRC_UTILS} ${SRC_MAP}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${CC} ${CFLAGS} ${OBJECTS} -o ${EXE}

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${RM} obj

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
