/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:14:50 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/09 04:23:21 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if there's a door at coordinate (x, y)
void	horz_door_at(t_mlx *mlx, int index, double x, double y)
{
	int	map_x;
	int	map_y;

	y = y - facing_up(mlx, index);
	map_x = (int)floor(x / TAIL);
	map_y = (int)floor(y / TAIL);
	if (mlx->mp->map[map_y][map_x] == 'D' && mlx->ray[index]->horz_door_hit_x == -1)
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

	x = x - facing_left(mlx, index);
	map_x = (int)floor(x / TAIL);
	map_y = (int)floor(y / TAIL);
	if (mlx->mp->map[map_y][map_x] == 'D' && mlx->ray[index]->vert_door_hit_x == -1)
	{
			mlx->ray[index]->vert_door_hit_x = x + facing_left(mlx, index);
			mlx->ray[index]->vert_door_hit_y = y;
	}
}

float	door_distance(float x1, float y1, float x2, float y2)
{
	float	x_diff;
	float	y_diff;

	x_diff = x2 - x1;
	y_diff = y2 - y1;
	return (sqrt((x_diff * x_diff) + (y_diff * y_diff)));
}

void	render_door(t_mlx *mlx, t_ray *ray, int i, float distance)
{
	int		x;
	int		y;
	float	wall_strip_height;

	wall_strip_height = (TAIL / (distance * cos(ray->ray_angle
					- mlx->plyr->rotation_angle))) * ((WIN_W / 2)
			/ tan(FOV_ANGLE / 2));
	x = i * WALL_STRIP_WIDTH;
	y = (WIN_H / 2) - (wall_strip_height / 2);
	mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wall_strip_height, 200, 200, 0);
}

float	vert_horz_door(t_mlx *mlx, int i, float horz_door, float vert_door)
{
	if (horz_door == INT_MAX && vert_door == INT_MAX)
		return (0);
	if (vert_door < horz_door)
	{
		mlx->ray[i]->vert_door = 1;
		return (vert_door);
	}
	if (horz_door < vert_door)
	{
		mlx->ray[i]->vert_door = 0;
		return (horz_door);
	}
	return (0);
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
	else if (mlx->ray[i]->vert_door_hit_x != -1)
	{
		vert_door = door_distance(mlx->plyr->x, mlx->plyr->y,
			mlx->ray[i]->vert_door_hit_x, mlx->ray[i]->vert_door_hit_y);
	}
	return (vert_horz_door(mlx, i, vert_door, horz_door));
}

void	render_3d_projected_doors(t_ray **rays, t_mlx *mlx)
{
	int		i;
	t_ray	*ray;
	float	distance;

	i = 0;
	while (i < NUM_RAYS)
	{
		ray = rays[i];
		distance = get_door_distance(mlx, i);
		if (distance != 0 && mlx->ray[i]->vert_door == 1)
		{
			mlx->ray[i]->door_x = mlx->ray[i]->vert_door_hit_x;
			mlx->ray[i]->door_y = mlx->ray[i]->vert_door_hit_y;
		}
		else if (distance != 0 && mlx->ray[i]->vert_door == 0)
		{
			mlx->ray[i]->door_x = mlx->ray[i]->horz_door_hit_x;
			mlx->ray[i]->door_y = mlx->ray[i]->horz_door_hit_y;
		}
		if (distance > (TAIL + 10) && distance < mlx->ray[i]->distance)
			render_door(mlx, ray, i, distance);
		i++;
	}
}
