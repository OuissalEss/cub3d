/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 04:48:49 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/11 05:01:02 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	door_add(t_mlx *mlx, t_ray *ray, int i, int x)
{
	char	*str;

	ray->offset_y = (i + (ray->wall_height / 2) - (WIN_H / 2))
		* ((double)mlx->mp->no->height / ray->wall_height);
	if (ray->offset_y < 0)
		ray->offset_y = 0;
	str = mlx->mp->d->data + (ray->offset_y * mlx->mp->d->size_l
			+ ray->offset_x * (mlx->mp->d->bpp / 8));
	my_mlx_pixel_put(mlx, x, i, *(unsigned int *)str);
}

void	calcul_door(t_mlx *mlx, t_ray *ray, int x)
{
	int		i;

	if (ray->vert_door)
		ray->offset_x = (int)ray->horz_door_hit_x % TAIL;
	else
		ray->offset_x = (int)ray->vert_door_hit_y % TAIL;
	i = ray->top_wall;
	while (i < ray->bottom_wall)
	{
		door_add(mlx, ray, i, x);
		i++;
	}
}

void	render_door(t_mlx *mlx, t_ray *ray, int i, float distance)
{
	int		y;
	float	wall_strip_height;

	wall_strip_height = (TAIL / (distance * cos(ray->ray_angle
					- mlx->plyr->rotation_angle))) * ((WIN_W / 2)
			/ tan(FOV_ANGLE / 2));
	y = (WIN_H / 2) - (wall_strip_height / 2);
	ray->wall_height = wall_strip_height;
	if (y < 0)
		y = 0;
	ray->top_wall = y;
	ray->bottom_wall = (WIN_H / 2) + (ray->wall_height / 2);
	if (ray->bottom_wall > WIN_H)
		ray->bottom_wall = WIN_H;
	calcul_door(mlx, ray, i);
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
		if (distance > (TAIL / 2) && distance < mlx->ray[i]->distance)
			render_door(mlx, ray, i, distance);
		i++;
	}
}
