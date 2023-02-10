/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_vert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:08:43 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/10 04:28:10 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	facing_left(t_mlx *mlx, int index)
{
	if (mlx->ray[index]->is_ray_facing_left)
		return (1);
	return (0);
}

float	get_xinterv(t_mlx *mlx, int index)
{
	float	xintercept;

	xintercept = (int)(mlx->plyr->x / TAIL) * TAIL;
	if (mlx->ray[index]->is_ray_facing_right)
		xintercept += TAIL;
	return (xintercept);
}

float	get_yinterv(t_mlx *mlx, int index, float xintercept)
{
	float	yintercept;

	yintercept = mlx->plyr->y + (xintercept - mlx->plyr->x)
		* tan(mlx->ray[index]->ray_angle);
	return (yintercept);
}

float	get_ystepv(t_mlx *mlx, int index)
{
	float	ystep;

	ystep = TAIL * tan(mlx->ray[index]->ray_angle);
	if (mlx->ray[index]->is_ray_facing_up && ystep > 0)
		ystep *= -1;
	if (mlx->ray[index]->is_ray_facing_down && ystep < 0)
		ystep *= -1;
	return (ystep);
}

float	get_xstepv(t_mlx *mlx, int index)
{
	float	xstep;

	xstep = TAIL;
	if (mlx->ray[index]->is_ray_facing_left)
		xstep *= -1;
	return (xstep);
}
