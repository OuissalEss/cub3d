# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 08:18:27 by oessamdi          #+#    #+#              #
#    Updated: 2023/02/09 00:40:09 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = 	cub3d.c cub3d_utils.c player.c init_data.c render_3d.c casting.c \
		\
		keys_handlers.c rays.c \
		\
		parsing/cub3d_utils0.c parsing/cub3d_utils1.c parsing/get_next_line.c \
		parsing/get_next_line_utils.c parsing/allocation.c parsing/directions.c \
		parsing/1stpart.c parsing/2ndpart.c parsing/map_utils.c parsing/error_msgs.c \
		parsing/plus_minus.c textures.c get_textures.c

CC = @gcc $(SRC) -lmlx -framework OpenGL -framework AppKit

MLX_PATH = mlx

MAKEMLX = make -C

DEBUG = -fsanitize=address -g

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f

all : $(NAME)

$(NAME) :
			$(CC) -o $(NAME) $(DEBUG)
	
fclean :
	$(RM) $(NAME)

re : fclean all
