# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 15:43:24 by slaajour          #+#    #+#              #
#    Updated: 2023/01/11 22:39:08 by slaajour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = cub3d.c cub3d_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		directions.c colors.c
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit 
OBJS	= 	$(SRCS:.c=.o)

DEBUG = -fsanitize=address -g

NAME	= 	cub3D
RM		= 	@rm -f

all:	$(NAME)

$(NAME):
	@cc $(FLAGS) $(SRCS) -o $(NAME) $(DEBUG)

bonus:
	@cc $(FLAGS) $(SRCS_BONUS) -o $(NAME) $(DEBUG)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all