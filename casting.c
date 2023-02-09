/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:31:43 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/07 20:41:44 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	facing_up(t_mlx *mlx, int index)
{
	if (mlx->ray[index]->is_ray_facing_up)
		return (1);
	return (0);
}

// Horizontal Ray-Grid Intersection Code
int	found_horz_wall(t_mlx *mlx, int index)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

	yintercept = (int)(mlx->plyr->y / TAIL) * TAIL;
	if (mlx->ray[index]->is_ray_facing_down)
		yintercept += TAIL;
	xintercept = mlx->plyr->x + (yintercept - mlx->plyr->y)
		/ tan(mlx->ray[index]->ray_angle);
	ystep = TAIL;
	if (mlx->ray[index]->is_ray_facing_up)
		ystep *= -1;
	xstep = TAIL / tan(mlx->ray[index]->ray_angle);
	if ((mlx->ray[index]->is_ray_facing_left && xstep > 0)
		|| (mlx->ray[index]->is_ray_facing_right && xstep < 0))
		xstep *= -1;
	while (xintercept >= 0 && xintercept <= WIN_W
		&& yintercept >= 0 && yintercept <= WIN_H)
	{
		if (has_wall_at(mlx, xintercept, yintercept - facing_up(mlx, index)))
		{
			mlx->ray[index]->horz_wall_hit_x = xintercept;
			mlx->ray[index]->horz_wall_hit_y = yintercept;
			return (1);
		}
		else
		{
			xintercept += xstep;
			yintercept += ystep;
		}
	}
	return (0);
}

int	facing_left(t_mlx *mlx, int index)
{
	if (mlx->ray[index]->is_ray_facing_left)
		return (1);
	return (0);
}

// Vertical Ray-Grid Intersection Code
int	found_vert_wall(t_mlx *mlx, int index)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

	xintercept = (int)(mlx->plyr->x / TAIL) * TAIL;
	if (mlx->ray[index]->is_ray_facing_right)
		xintercept += TAIL;
	yintercept = mlx->plyr->y + (xintercept - mlx->plyr->x)
		* tan(mlx->ray[index]->ray_angle);
	xstep = TAIL;
	if (mlx->ray[index]->is_ray_facing_left)
		xstep *= -1;
	ystep = TAIL * tan(mlx->ray[index]->ray_angle);
	if (mlx->ray[index]->is_ray_facing_up && ystep > 0)
		ystep *= -1;
	// else
	// 	ystep *= 1;
	if (mlx->ray[index]->is_ray_facing_down && ystep < 0)
		ystep *= -1;
	// else
	// 	ystep *= 1;
	next_vert_touch_x = xintercept;
	next_vert_touch_y = yintercept;
	while (next_vert_touch_x >= 0 && next_vert_touch_x <= WIN_W
		&& next_vert_touch_y >= 0 && next_vert_touch_y <= WIN_H)
	{
		if (has_wall_at(mlx, next_vert_touch_x - facing_left(mlx, index),
				next_vert_touch_y))
		{
			mlx->ray[index]->vert_wall_hit_x = next_vert_touch_x;
			mlx->ray[index]->vert_wall_hit_y = next_vert_touch_y;
			return (1);
		}
		else
		{
			next_vert_touch_x += xstep;
			next_vert_touch_y += ystep;
		}
	}
	return (0);
}

void	cast(t_mlx *mlx, int index)
{
	float	horz_hit_distance;
	float	vert_hit_distance;

	horz_hit_distance = INT_MAX;
	if (found_horz_wall(mlx, index) == 1)
		horz_hit_distance = distance_between_points(mlx->plyr->x, mlx->plyr->y,
				mlx->ray[index]->horz_wall_hit_x,
				mlx->ray[index]->horz_wall_hit_y);
	vert_hit_distance = INT_MAX;
	if (found_vert_wall(mlx, index) == 1)
		vert_hit_distance = distance_between_points(mlx->plyr->x, mlx->plyr->y,
				mlx->ray[index]->vert_wall_hit_x,
				mlx->ray[index]->vert_wall_hit_y);
	if (horz_hit_distance < vert_hit_distance)
	{
		mlx->ray[index]->wall_hit_x = mlx->ray[index]->horz_wall_hit_x;
		mlx->ray[index]->wall_hit_y = mlx->ray[index]->horz_wall_hit_y;
		mlx->ray[index]->distance = horz_hit_distance;
		mlx->ray[index]->was_hit_vertical = 0;
	}
	else
	{
		mlx->ray[index]->wall_hit_x = mlx->ray[index]->vert_wall_hit_x;
		mlx->ray[index]->wall_hit_y = mlx->ray[index]->vert_wall_hit_y;
		mlx->ray[index]->distance = vert_hit_distance;
		mlx->ray[index]->was_hit_vertical = 1;
	}
}
