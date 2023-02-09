/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 05:35:25 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/09 00:30:06 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "cub3d.h"
# include "parsing/parsing.h"

// typedef struct s_send{
// 	int	wall_height;
// 	int	top_wall;
// }	t_send;

void	get_textures(t_mlx *mlx, t_game *game);
void	error_path(void);
void	calcul(t_mlx *mlx, t_ray *ray, int x);
void	east_add(t_mlx *mlx, t_ray *ray, int i, int x);
void	west_add(t_mlx *mlx, t_ray *ray, int i, int x);
void	south_add(t_mlx *mlx, t_ray *ray, int i, int x);
void	north_add(t_mlx *mlx, t_ray *ray, int i, int x);

#endif