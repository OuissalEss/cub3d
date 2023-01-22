# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:43:24 by slaajour          #+#    #+#              #
#    Updated: 2023/01/22 12:27:22 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRCS 	=	cub3d.c parsing/cub3d_utils0.c parsing/cub3d_utils1.c parsing/get_next_line/get_next_line.c \
			parsing/get_next_line/get_next_line_utils.c parsing/allocation.c parsing/directions.c \
			parsing/1stmap.c parsing/2ndmap.c 

CC = @gcc

FLAGS	=	-Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit 

OBJS	= 	$(SRCS:.c=.o)

DEBUG	=	-fsanitize=address -g

RM		= 	@rm -f

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) 

all:	$(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all
