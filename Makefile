# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 08:18:27 by oessamdi          #+#    #+#              #
#    Updated: 2023/02/16 11:06:56 by oessamdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_B = cub3D_bonus


SRC =	mandatory/cub3d.c mandatory/cub3d_utils.c mandatory/player.c mandatory/init_data.c mandatory/render_3d.c mandatory/casting.c \
		\
		mandatory/keys_handlers.c mandatory/rays.c mandatory/draw_map.c mandatory/casting_horz.c mandatory/casting_vert.c \
		\
		mandatory/parsing/cub3d_utils0.c mandatory/parsing/cub3d_utils1.c mandatory/parsing/get_next_line.c \
		mandatory/parsing/get_next_line_utils.c mandatory/parsing/allocation.c mandatory/parsing/directions.c \
		mandatory/parsing/1stpart.c mandatory/parsing/2ndpart.c mandatory/parsing/map_utils.c mandatory/parsing/error_msgs.c \
		mandatory/parsing/plus_minus.c mandatory/textures.c mandatory/get_textures.c

SRC_B =	bonus/cub3d.c bonus/cub3d_utils.c bonus/player.c bonus/init_data.c bonus/render_3d.c bonus/casting.c \
		\
		bonus/keys_handlers.c bonus/rays.c bonus/doors.c bonus/draw_map.c bonus/casting_horz.c bonus/casting_vert.c \
		\
		bonus/parsing/cub3d_utils0.c bonus/parsing/cub3d_utils1.c bonus/parsing/get_next_line.c \
		bonus/parsing/get_next_line_utils.c bonus/parsing/allocation.c bonus/parsing/directions.c \
		bonus/parsing/1stpart.c bonus/parsing/2ndpart.c bonus/parsing/map_utils.c bonus/parsing/error_msgs.c \
		bonus/parsing/plus_minus.c bonus/textures.c bonus/get_textures.c bonus/render_door.c


CC = @gcc $(SRC) -lmlx -framework OpenGL -framework AppKit

CC_B = @gcc $(SRC_B) -lmlx -framework OpenGL -framework AppKit


MLX_PATH = mlx

MAKEMLX = make -C

DEBUG = -fsanitize=address -g

CFLAGS = -Wall -Wextra -Werror

RM = @rm -f


all : $(NAME)

$(NAME) :
		$(CC) -o $(NAME)


bonus : $(NAME_B)

$(NAME_B) :
		$(CC_B) -o $(NAME_B)


clean :
		$(RM) *.o mandatory/*.o mandatory/parsing/*.o bonus/*.o bonus/parsing/*.o
		@echo "All the .o files Removed"

fclean :
		$(RM) $(NAME) $(NAME_B)
		@echo "Executable removed"

re : fclean all
