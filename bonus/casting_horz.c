/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_horz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:07:53 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/11 03:50:26 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	facing_up(t_mlx *mlx, int index)
{
	if (mlx->ray[index]->is_ray_facing_up)
		return (1);
	return (0);
}

float	get_yinterh(t_mlx *mlx, int index)
{
	float	yintercept;

	yintercept = (int)(mlx->plyr->y / TAIL) * TAIL;
	if (mlx->ray[index]->is_ray_facing_down)
		yintercept += TAIL;
	return (yintercept);
}

float	get_xinterh(t_mlx *mlx, int index, float yintercept)
{
	float	xintercept;

	xintercept = mlx->plyr->x + (yintercept - mlx->plyr->y)
		/ tan(mlx->ray[index]->ray_angle);
	return (xintercept);
}

float	get_ysteph(t_mlx *mlx, int index)
{
	float	ystep;

	ystep = TAIL;
	if (mlx->ray[index]->is_ray_facing_up)
		ystep *= -1;
	return (ystep);
}

float	get_xsteph(t_mlx *mlx, int index)
{
	float	xstep;

	xstep = TAIL / tan(mlx->ray[index]->ray_angle);
	if (mlx->ray[index]->is_ray_facing_left && xstep > 0)
		xstep *= -1;
	if (mlx->ray[index]->is_ray_facing_right && xstep < 0)
		xstep *= -1;
	return (xstep);
}
