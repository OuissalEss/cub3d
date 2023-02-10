/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:31:43 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/10 02:09:02 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Horizontal Ray-Grid Intersection Code
int	found_horz_wall(t_mlx *mlx, int index)
{
	float	xinter;
	float	yinter;
	float	xstep;
	float	ystep;

	yinter = get_yinterh(mlx, index);
	xinter = get_xinterh(mlx, index, yinter);
	ystep = get_ysteph(mlx, index);
	xstep = get_xsteph(mlx, index);
	while (xinter >= 0 && xinter <= (mlx->mp->width * TAIL)
		&& yinter >= 0 && yinter <= (mlx->mp->height * TAIL))
	{
		if (has_wall_at(mlx, xinter, yinter - facing_up(mlx, index)))
		{
			mlx->ray[index]->horz_wall_hit_x = xinter;
			mlx->ray[index]->horz_wall_hit_y = yinter;
			return (1);
		}
		else
		{
			xinter += xstep;
			yinter += ystep;
		}
	}
	return (0);
}

// Vertical Ray-Grid Intersection Code
int	found_vert_wall(t_mlx *mlx, int index)
{
	float	xinter;
	float	yinter;
	float	xstep;
	float	ystep;

	xinter = get_xinterv(mlx, index);
	yinter = get_yinterv(mlx, index, xinter);
	xstep = get_xstepv(mlx, index);
	ystep = get_ystepv(mlx, index);
	while (xinter >= 0 && xinter <= (mlx->mp->width * TAIL)
		&& yinter >= 0 && yinter <= (mlx->mp->height * TAIL))
	{
		if (has_wall_at(mlx, xinter - facing_left(mlx, index), yinter))
		{
			mlx->ray[index]->vert_wall_hit_x = xinter;
			mlx->ray[index]->vert_wall_hit_y = yinter;
			return (1);
		}
		else
		{
			xinter += xstep;
			yinter += ystep;
		}
	}
	return (0);
}

void	get_distance(t_mlx *mlx, int index, float distance, int x)
{
	if (x == 0)
	{
		mlx->ray[index]->wall_hit_x = mlx->ray[index]->horz_wall_hit_x;
		mlx->ray[index]->wall_hit_y = mlx->ray[index]->horz_wall_hit_y;
		mlx->ray[index]->distance = distance;
		mlx->ray[index]->was_hit_vertical = 0;
	}
	else
	{
		mlx->ray[index]->wall_hit_x = mlx->ray[index]->vert_wall_hit_x;
		mlx->ray[index]->wall_hit_y = mlx->ray[index]->vert_wall_hit_y;
		mlx->ray[index]->distance = distance;
		mlx->ray[index]->was_hit_vertical = 1;
	}
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
		get_distance(mlx, index, horz_hit_distance, 0);
	else
		get_distance(mlx, index, vert_hit_distance, 1);
}
