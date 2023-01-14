/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:36 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/14 03:47:57 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

typedef struct s_game{
	char	**map;
	char	**map1;
	char	**map2;
	int		len;
	int		len_map1;
	int		len_map2;
}	t_game;

		/* ALLOCATION */
void	check_cub(char *str);
void	read_file(int fd, char *av, t_game *game);
int		len_file(char *av);
int		both_len(t_game *game);
void	both_malloc(t_game *game, char *av);

		/* DIRECTIONS AND COLORS */
void	directions(t_game *game);
void	north_check(t_game *game);
void	south_check(t_game *game);
void	west_check(t_game *game);
void	east_check(t_game *game);
void	floor_check(t_game *game);
void	ceilling_check(t_game *game);

#endif