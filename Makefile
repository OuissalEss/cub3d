# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:43:24 by slaajour          #+#    #+#              #
#    Updated: 2023/01/21 05:36:20 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D

SRCS 	=	cub3d.c cub3d_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			allocation.c directions.c 1stmap.c

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
