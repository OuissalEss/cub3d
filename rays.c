/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 07:56:08 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/07 22:10:21 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_angle(float angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

t_ray	*create_ray(float ray_angle)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->ray_angle = normalize_angle(ray_angle);
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	ray->was_hit_vertical = 0;
	ray->is_ray_facing_down = (ray->ray_angle > 0 && ray->ray_angle < M_PI);
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right
		= (ray->ray_angle < 0.5 * M_PI || ray->ray_angle > 1.5 * M_PI);
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
	return (ray);
}

// Cast the 2d rays
void	cast_2d_rays(t_mlx *mlx)
{
	int		i;
	int		column_id;
	float	ray_angle;

	column_id = 0;
	i = 0;
	ray_angle = mlx->plyr->rotation_angle - (FOV_ANGLE / 2);
	mlx->ray_count = 0;
	while (i < NUM_RAYS)
	{
		ray_angle = normalize_angle(ray_angle);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		column_id++;
		i++;
		mlx->ray_count++;
	}
}

float	distance_between_points(float x1, float y1, float x2, float y2)
{
	float	x_diff;
	float	y_diff;

	x_diff = x2 - x1;
	y_diff = y2 - y1;
	return (sqrt((x_diff * x_diff) + (y_diff * y_diff)));
}

void	cast_all_rays(t_mlx *mlx)
{
	int		i;
	float	ray_angle;

	ray_angle = mlx->plyr->rotation_angle - (FOV_ANGLE / 2);
	if (!mlx->ray)
		return ;
	i = 0;
	while (i < NUM_RAYS)
	{
		if (mlx->ray[i])
			free(mlx->ray[i]);
		mlx->ray[i] = create_ray(ray_angle);
		if (!mlx->ray[i])
			return ;
		cast(mlx, i);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		i++;
	}
}
