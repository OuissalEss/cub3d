/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:14:50 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/11 04:49:09 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if there's a door at coordinate (x, y)
void	horz_door_at(t_mlx *mlx, int index, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x / TAIL);
	map_y = (int)floor(y / TAIL);
	if (mlx->mp->map[map_y][map_x] == 'D'
		&& mlx->ray[index]->horz_door_hit_x == -1)
	{
			mlx->ray[index]->horz_door_hit_x = x;
			mlx->ray[index]->horz_door_hit_y = y + facing_up(mlx, index);
	}
}

// Check if there's a door at coordinate (x, y)
void	vert_door_at(t_mlx *mlx, int index, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x / TAIL);
	map_y = (int)floor(y / TAIL);
	if (mlx->mp->map[map_y][map_x] == 'D'
		&& mlx->ray[index]->vert_door_hit_x == -1)
	{
			mlx->ray[index]->vert_door_hit_x = x + facing_left(mlx, index);
			mlx->ray[index]->vert_door_hit_y = y;
	}
}

float	vert_horz_door(t_mlx *mlx, int i, float horz_door, float vert_door)
{
	if (horz_door == INT_MAX && vert_door == INT_MAX)
		return (0);
	if (vert_door > horz_door)
	{
		mlx->ray[i]->vert_door = 0;
		return (horz_door);
	}
	else
	{
		mlx->ray[i]->vert_door = 1;
		return (vert_door);
	}
	return (0);
}

float	door_distance(float x1, float y1, float x2, float y2)
{
	float	x_diff;
	float	y_diff;

	x_diff = x2 - x1;
	y_diff = y2 - y1;
	return (sqrt((x_diff * x_diff) + (y_diff * y_diff)));
}

float	get_door_distance(t_mlx *mlx, int i)
{
	float	horz_door;
	float	vert_door;

	horz_door = INT_MAX;
	vert_door = INT_MAX;
	if (mlx->ray[i]->horz_door_hit_x != -1)
	{
		horz_door = door_distance(mlx->plyr->x, mlx->plyr->y,
				mlx->ray[i]->horz_door_hit_x, mlx->ray[i]->horz_door_hit_y);
	}
	if (mlx->ray[i]->vert_door_hit_x != -1)
	{
		vert_door = door_distance(mlx->plyr->x, mlx->plyr->y,
				mlx->ray[i]->vert_door_hit_x, mlx->ray[i]->vert_door_hit_y);
	}
	return (vert_horz_door(mlx, i, vert_door, horz_door));
}
