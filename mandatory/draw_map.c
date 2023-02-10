/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:28:47 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/10 02:49:25 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_f_c(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H / 2)
	{
		j = 0;
		while (j < WIN_W)
		{
			put_pixel(mlx, j, i, mlx->mp->rgb_c);
			j++;
		}
		i++;
	}
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			put_pixel(mlx, j, i, mlx->mp->rgb_f);
			j++;
		}
		i++;
	}
}

// Draw the 2D game map
void	draw_map(t_mlx *mlx)
{
	int	h;
	int	w;
	int	x;
	int	y;

	h = 0;
	while (h < mlx->mp->height)
	{
		w = 0;
		while (w < mlx->mp->width)
		{
			x = w * TAIL * SCALE;
			y = h * TAIL * SCALE;
			if (mlx->mp->map[h][w] == '1')
				mlx_rectangle(mlx, x, y, 0xFFFFFF);
			if (mlx->mp->map[h][w] != '1' && mlx->mp->map[h][w] != ' '
				&& mlx->mp->map[h][w] != '\n')
				mlx_rectangle(mlx, x, y, 0x000000);
			w++;
		}
		h++;
	}
}

// Draw the 2D player
void	draw_player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	r;
	int	i;
	int	j;

	x = mlx->plyr->x;
	y = mlx->plyr->y;
	r = mlx->plyr->radius;
	i = -r;
	while (i <= r)
	{
		j = -r;
		while (j <= r)
		{
			if (i * i + j * j <= r * r)
				put_pixel(mlx, (x + i) * SCALE, (y + j) * SCALE, 0x00FFFF);
			j++;
		}
		i++;
	}
}
