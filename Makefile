# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 08:18:27 by oessamdi          #+#    #+#              #
#    Updated: 2023/02/05 09:36:12 by oessamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = 	cub3d.c cub3d_utils.c player.c init_data.c render_3d.c casting.c \
		\
		keys_handlers.c rays.c \
		\
		parsing/cub3d_utils0.c parsing/cub3d_utils1.c parsing/get_next_line/get_next_line.c \
		parsing/get_next_line/get_next_line_utils.c parsing/allocation.c parsing/directions.c \
		parsing/1stpart.c parsing/2ndpart.c parsing/map_utils.c parsing/error_msgs.c \
		parsing/plus_minus.c

CC = @gcc $(SRC) -lmlx -framework OpenGL -framework AppKit

MLX_PATH = mlx

MAKEMLX = make -C

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

all : $(NAME)

$(NAME) :
			$(CC) -o $(NAME)
	
fclean :
	$(RM) $(NAME)

re : fclean all
