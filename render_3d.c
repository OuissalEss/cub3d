/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:33:36 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/09 02:14:13 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "textures.h"

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
	int		x;
	int		y;
	t_ray	*ray;
	float	wall_strip_height;

	x = 0;
	while (x < NUM_RAYS)
	{
		ray = rays[x];
		wall_strip_height = (TAIL / (ray->distance * cos(ray->ray_angle - mlx->plyr->rotation_angle))) * ((WIN_W / 2) / tan(FOV_ANGLE / 2));
		y = ((WIN_H / 2) - wall_strip_height / 2);
		ray->wall_height = wall_strip_height;
		if (y < 0)
		 	y = 0;
		ray->top_wall = y;
		ray->bottom_wall = (WIN_H / 2) + (wall_strip_height / 2);
		if (ray->bottom_wall > 1000)
		  	ray->bottom_wall = 1000;
		if (ray->was_hit_vertical)
		{
			ray->offset_x = (int)ray->wall_hit_y % TAIL;
			calcul(mlx, ray, x);
		}
		else
		{
			ray->offset_x = (int)ray->wall_hit_x % TAIL;
			calcul(mlx, ray, x);
		}
		x++;
		
	}
}
