/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 11:18:49 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/10 06:28:48 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "textures.h"
#include "parsing/parsing.h"

void	init_directions(t_mlx *mlx)
{
	mlx->mp->no = malloc(sizeof(t_img));
	mlx->mp->so = malloc(sizeof(t_img));
	mlx->mp->we = malloc(sizeof(t_img));
	mlx->mp->ea = malloc(sizeof(t_img));
}

void	get_textures(t_mlx *mlx, t_game *game)
{
	init_directions(mlx);
	mlx->mp->no->path = game->no;
	mlx->mp->no->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->mp->no->path, &mlx->mp->no->width, &mlx->mp->no->height);
	mlx->mp->so->path = game->so;
	mlx->mp->so->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->mp->so->path, &mlx->mp->so->width, &mlx->mp->so->height);
	mlx->mp->we->path = game->we;
	mlx->mp->we->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->mp->we->path, &mlx->mp->we->width, &mlx->mp->we->height);
	mlx->mp->ea->path = game->ea;
	mlx->mp->ea->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			mlx->mp->ea->path, &mlx->mp->ea->width, &mlx->mp->ea->height);
	if (!mlx->mp->no->img_ptr || !mlx->mp->so->img_ptr || !mlx->mp->we->img_ptr
		|| !mlx->mp->ea->img_ptr)
		error_path();
	mlx->mp->no->data = mlx_get_data_addr(mlx->mp->no->img_ptr,
			&mlx->mp->no->bpp, &mlx->mp->no->size_l, &mlx->mp->no->endian);
	mlx->mp->so->data = mlx_get_data_addr(mlx->mp->so->img_ptr,
			&mlx->mp->so->bpp, &mlx->mp->so->size_l, &mlx->mp->so->endian);
	mlx->mp->we->data = mlx_get_data_addr(mlx->mp->we->img_ptr,
			&mlx->mp->we->bpp, &mlx->mp->we->size_l, &mlx->mp->we->endian);
	mlx->mp->ea->data = mlx_get_data_addr(mlx->mp->ea->img_ptr,
			&mlx->mp->ea->bpp, &mlx->mp->ea->size_l, &mlx->mp->ea->endian);
}

void	calcul(t_mlx *mlx, t_ray *ray, int x)
{
	int		i;

	if (ray->was_hit_vertical)
		ray->offset_x = (int)ray->wall_hit_y % TAIL;
	else
		ray->offset_x = (int)ray->wall_hit_x % TAIL;
	i = ray->top_wall;
	while (i < ray->bottom_wall)
	{
		if (ray->was_hit_vertical && ray->is_ray_facing_right)
			east_add(mlx, ray, i, x);
		else if (ray->was_hit_vertical && ray->is_ray_facing_left)
			west_add(mlx, ray, i, x);
		else if (!ray->was_hit_vertical && ray->is_ray_facing_down)
			south_add(mlx, ray, i, x);
		else if (!ray->was_hit_vertical && ray->is_ray_facing_up)
			north_add(mlx, ray, i, x);
		i++;
	}
}
