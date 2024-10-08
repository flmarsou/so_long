# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/17 12:59:58 by flmarsou          #+#    #+#              #
#    Updated: 2024/09/06 09:23:33 by flmarsou         ###   ########.fr        #
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
				./src/utils/ft_itoa.c \

SRC_MAP		=	./src/map/init_map.c \
				./src/map/get_next_line.c \
				./src/map/free_map.c \

SRC_PARSER	=	./src/parser/is_valid_char.c \
				./src/parser/is_valid_count.c \
				./src/parser/is_valid_shape.c \
				./src/parser/is_valid_close.c \
				./src/parser/is_valid_path.c \

SRC_DISPLAY	=	./src/display/init_display.c \
				./src/display/init_sprites.c \
				./src/display/walls/init_wall_sprites.c \
				./src/display/walls/which_inner_wall.c \
				./src/display/walls/which_outer_wall.c \
				./src/display/walls/display_walls.c \
				./src/display/floors/display_floors.c \
				./src/display/floors/init_floor_sprites.c \
				./src/display/floors/which_floor.c \
				./src/display/players/display_player.c \
				./src/display/players/init_player_sprites.c \
				./src/display/collectibles/display_collectibles.c \
				./src/display/collectibles/init_collectible_sprites.c \
				./src/display/exits/display_exit.c \
				./src/display/exits/init_exit_sprites.c \

SRC_GAME	=	./src/game/handle_keypress.c \
				./src/game/handle_text.c \
				./src/game/player_move.c \
				./src/game/enemy_move.c \
				./src/game/print_map.c \
				./src/game/close_window.c \

SOURCES		=	${SRC} ${SRC_UTILS} ${SRC_MAP} ${SRC_PARSER} ${SRC_DISPLAY} ${SRC_GAME}
OBJECTS		=	${SOURCES:%.c=obj/%.o}

# Libraries
MINILIBX	=	./includes/.MiniLibX

# Variables
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g
RM			=	rm -rf

# Makefile
all:		${EXE}

${EXE}:		${OBJECTS}
			@${MAKE} -C ${MINILIBX} > /dev/null 2>&1
			@${CC} ${CFLAGS} ${OBJECTS} -L${MINILIBX} -lmlx -lX11 -lXext -lm -o ${EXE}

obj/%.o:	%.c
			@mkdir -p obj/$(dir $<)
			@${CC} ${CFLAGS} -c $< -o $@

clean:
			@${MAKE} -C ${MINILIBX} clean > /dev/null
			@${RM} obj

fclean:		clean
			@${RM} ${EXE}

re:			fclean all

.PHONY:		all clean fclean re
