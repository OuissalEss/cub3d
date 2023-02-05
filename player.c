/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:18:32 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/05 08:52:12 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_player_id(t_mlx *mlx, int index)
{
	if (index == N)
		mlx->plyr->rotation_angle = NORTH;
	else if (index == S)
		mlx->plyr->rotation_angle = SOUTH;
	else if (index == E)
		mlx->plyr->rotation_angle = EAST;
	else if (index == W)
		mlx->plyr->rotation_angle = WEST;
	if (index == N || index == S || index == E || index == W)
		return (1);
	return (0);
}

// Save Initial player position from the config map
void	player_position(t_mlx *mlx)
{
	int	h;
	int	w;

	h = 0;
	while (h < mlx->mp->height)
	{
		w = 0;
		while (w < mlx->mp->width)
		{
			if (is_valid_player_id(mlx, mlx->mp->map[h][w]))
			{
				mlx->plyr->x = w * TAIL + (TAIL / 2);
				mlx->plyr->y = h * TAIL + (TAIL / 2);
			}
			w++;
		}
		h++;
	}
}

void	init_player(t_mlx *mlx)
{
	mlx->plyr->x = 0;
	mlx->plyr->y = 0;
	mlx->plyr->radius = 4;
	mlx->plyr->turn_direction = 0;
	mlx->plyr->walk_direction = 0;
	mlx->plyr->rotation_angle = PI / 2;
	mlx->plyr->move_speed = 10;
	mlx->plyr->rotation_speed = 4 * (PI / 180);
	player_position(mlx);
}
