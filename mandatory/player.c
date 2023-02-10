/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:18:32 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/10 05:23:54 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Update the player data on each key press
void	update_player(t_mlx *mlx)
{
	int	move_step;
	int	plyr_x;
	int	plyr_y;

	mlx->plyr->rotation_angle += mlx->plyr->turn_direction
		* mlx->plyr->rotation_speed;
	move_step = mlx->plyr->walk_direction * mlx->plyr->move_speed;
	plyr_x = mlx->plyr->x + cos(mlx->plyr->rotation_angle) * move_step;
	plyr_y = mlx->plyr->y + sin(mlx->plyr->rotation_angle) * move_step;
	if (mlx->plyr->walk_rotation != 0)
	{
		move_step = mlx->plyr->move_speed * mlx->plyr->walk_rotation;
		plyr_y = mlx->plyr->y - cos(mlx->plyr->rotation_angle) * move_step;
		plyr_x = mlx->plyr->x + sin(mlx->plyr->rotation_angle) * move_step;
	}
	if (!has_wall_at(mlx, plyr_x + 5, plyr_y) && !has_wall_at(mlx, plyr_x - 5, plyr_y) && !has_wall_at(mlx, plyr_x, plyr_y + 5) && !has_wall_at(mlx, plyr_x, plyr_y - 5))
	{
		mlx->plyr->x = plyr_x;
		mlx->plyr->y = plyr_y;
	}
}

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
	mlx->plyr->move_speed = 20;
	mlx->plyr->rotation_speed = 4 * (PI / 180);
	player_position(mlx);
}
