/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:33:36 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/05 09:36:06 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

void	mlx_rectangle(t_mlx *mlx, int x, int y, int width, int height, int r, int g, int b)
{
	int	i;
	int	j;

	i = x;
	while (i < x + width)
	{
		j = y;
		while (j < y + height)
		{
			if (i >= 0 && i < WIN_W && j >= 0 && j < WIN_H)
				put_pixel(mlx, i, j, create_rgb(r, g, b));
			j++;
		}
		i++;
	}
}

void	render_3d_projected_walls(t_ray **rays, t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;
	t_ray	*ray;
	float	wall_strip_height;

	i = 0;
	while (i < NUM_RAYS)
	{
		ray = rays[i];
		wall_strip_height = (TAIL / (ray->distance * cos(ray->ray_angle - mlx->plyr->rotation_angle))) * ((WIN_W / 2) / tan(FOV_ANGLE / 2));
		x = i * WALL_STRIP_WIDTH;
		y = (WIN_H / 2) - (wall_strip_height / 2);
		if (ray->was_hit_vertical)
		{
			if (ray->ray_angle > (PI / 2) && ray->ray_angle < (3 * PI / 2))
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wall_strip_height, 0, 0, 255);
			else
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wall_strip_height, 0, 255, 255);
		}
		else
		{
			if (ray->ray_angle > 0 && ray->ray_angle < PI)
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wall_strip_height, 153, 0, 153);
			else
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wall_strip_height, 255, 0, 255);
		}
		i++;
	}
}
