# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsacquin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 13:44:39 by fsacquin          #+#    #+#              #
#    Updated: 2021/06/07 16:25:00 by fsacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -lXext -lX11 -lm -Werror -Wall -Wextra -g3

HEADER = ./cub3D.h

SRCS = ./ft_atoi.c\
 ./ft_split.c\
 ./get_next_line_utils.c\
 ./get_next_line.c\
 ./input_parsing.c\
 ./labyrinth_parsing.c\
 ./parsing_utils.c\
 ./trgb_utils.c\
 ./error_central.c\
 ./init_utils.c\
 ./floodfill.c\
 ./screen_manager.c\
 ./raycasting.c\
 ./floodfill_utils.c\
 ./parsing_utils_2.c\
 ./parsing_utils_3.c\
 ./parsing_utils_4.c\
 ./key_movement.c\
 ./strafe_movement.c\
 ./key_management.c\
 ./closing_utils.c\
 ./wall_checks.c\
 ./raycasting_utils.c\
 ./raycasting_utils_2.c\
 ./error_message.c\
 ./main.c

SRCS_BONUS = ./minimap_bonus.c

OBJS = $(SRCS:.c=.o)

all	:	$(NAME)

MLX_FILE = mlx_linux/libmlx.a

$(MLX_FILE):
			make --no-print-directory -C mlx_linux all

valgrind : all 
			valgrind --leak-check=full --show-leak-kinds=all ./cub3D maps/default.cub

${NAME}:	$(MLX_FILE) ${OBJS}
			gcc -o ${NAME} ${SRCS} $(MLX_FILE) ${CFLAGS} -I./

clean	:	
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

libclean:	
			make --no-print-directory -C mlx_linux clean

re		: clean all

.PHONY:	re clean fclean all
