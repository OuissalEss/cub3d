/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:36 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/11 22:39:40 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct s_game{
	char	**map;
}	t_game;

		/* CUB3D UTILS */
char	**ft_split(char const *s, char c);
int		ft_strlcpy(char *dst, const char *src, int dstsize);

		/* DIRECTIONS AND COLORS */
void	directions(t_game *game);
void	north_check(t_game *game);
void	south_check(t_game *game);
void	west_check(t_game *game);
void	east_check(t_game *game);
void	floor_check(t_game *game);
void	ceilling_check(t_game *game);

#endif