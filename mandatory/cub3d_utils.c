/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:01:13 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/10 06:04:10 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Check if there's a wall at coordinate (x, y)
int	has_wall_at(t_mlx *mlx, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(x / TAIL);
	map_y = (int)floor(y / TAIL);
	if (map_x < 0 || map_x >= mlx->mp->width
		|| map_y < 0 || map_y >= mlx->mp->height)
		return (1);
	if (mlx->mp->map[map_y][map_x] == '1' || mlx->mp->map[map_y][map_x] == '\n')
		return (1);
	return (0);
}

// Insert pixel into the img buffer
void	put_pixel(t_mlx *mlx, int x, int y, unsigned int color)
{
	int	*dst;

	dst = (int *)(mlx->img->data
			+ (y * mlx->img->size_l + x * (mlx->img->bpp / 8)));
	*dst = color;
}
// void	draw_map(t_mlx *mlx)
// {
// 	int	h;
// 	int	w;
// 	int	x;
// 	int	y;

// 	h = 0;
// 	while (h < mlx->mp->height)
// 	{
// 		w = 0;
// 		while (w < mlx->mp->width)
// 		{
// 			x = w * TAIL * SCALE;
// 			y = h * TAIL * SCALE;
// 			if (mlx->mp->map[h][w] == '1')
// 				mlx_rectangle(mlx, x, y, 255, 255, 255);
// 			else if (mlx->mp->map[h][w] == 'D')
// 				mlx_rectangle(mlx, x, y, SCALE * TAIL, SCALE * TAIL, 0, 250, 0);
// 			else if (mlx->mp->map[h][w] != ' ' && mlx->mp->map[h][w] != '\n')
// 				mlx_rectangle(mlx, x, y, SCALE * TAIL, SCALE * TAIL, 0, 0, 0);
// 			w++;
// 		}
// 		h++;
// 	}
// }

void	update_window(t_mlx *mlx)
{
	draw_f_c(mlx);
	update_player(mlx);
	cast_all_rays(mlx);
	render_3d_projected_walls(mlx->ray, mlx);
	draw_map(mlx);
	draw_player(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
}
