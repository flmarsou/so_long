# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 12:59:58 by flmarsou          #+#    #+#              #
#    Updated: 2024/08/01 14:11:01 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			=	so_long

# Files
SRC			=	./src/main.c \

SRC_UTILS	=	./src/utils/ft_putchar.c \
				./src/utils/ft_putstr.c \
				./src/utils/ft_putnbr.c \
				./src/utils/ft_putuni.c \
				./src/utils/ft_printf.c \
				./src/utils/ft_puterr.c \
				./src/utils/ft_strlen.c \
				./src/utils/ft_strcmp.c \
				./src/utils/ft_strchr.c \
				./src/utils/ft_strdup.c \
				./src/utils/ft_strjoin.c \

SRC_MAP		=	./src/map/init_map.c \
				./src/map/get_next_line.c \
				./src/map/free_map.c \

SRC_PARSER	=	./src/parser/is_valid_char.c \
				./src/parser/is_valid_count.c \
				./src/parser/is_valid_shape.c \
				./src/parser/is_valid_close.c \
				./src/parser/is_valid_path.c \

SOURCES		=	${SRC} ${SRC_UTILS} ${SRC_MAP} ${SRC_PARSER}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
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
