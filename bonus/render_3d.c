/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:33:36 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/11 05:00:52 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_rectangle(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = x;
	width = TAIL * SCALE;
	height = TAIL * SCALE;
	while (i <= x + width)
	{
		j = y;
		while (j <= y + height)
		{
			if (i >= 0 && i < WIN_W && j >= 0 && j < WIN_H)
				put_pixel(mlx, i, j, color);
			j++;
		}
		i++;
	}
}

void	render_3d_projected_walls(t_ray **rays, t_mlx *mlx)
{
	int		x;
	int		y;
	t_ray	*ray;
	float	wall_strip_height;

	x = 0;
	while (x < NUM_RAYS)
	{
		ray = rays[x];
		wall_strip_height = (TAIL / (ray->distance * cos(ray->ray_angle
						- mlx->plyr->rotation_angle))) * ((WIN_W / 2)
				/ tan(FOV_ANGLE / 2));
		y = ((WIN_H / 2) - (wall_strip_height / 2));
		ray->wall_height = wall_strip_height;
		if (y < 0)
			y = 0;
		ray->top_wall = y;
		ray->bottom_wall = (WIN_H / 2) + (ray->wall_height / 2);
		if (ray->bottom_wall > WIN_H)
			ray->bottom_wall = WIN_H;
		calcul(mlx, ray, x, 0);
		x++;
	}
}
