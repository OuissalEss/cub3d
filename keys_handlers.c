/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:00:55 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/05 09:10:16 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keyCode, t_mlx *mlx)
{
	if (keyCode == UP_ARROW)
		mlx->plyr->walk_direction = +1;
	else if (keyCode == DOWN_ARROW)
		mlx->plyr->walk_direction = -1;
	else if (keyCode == RIGHT_ARROW)
		mlx->plyr->turn_direction = +1;
	else if (keyCode == LEFT_ARROW)
		mlx->plyr->turn_direction = -1;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img->data = mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	update_window(mlx);
	return (0);
}

int	key_release(int keyCode, t_mlx *mlx)
{
	if (keyCode == UP_ARROW)
		mlx->plyr->walk_direction = 0;
	else if (keyCode == DOWN_ARROW)
		mlx->plyr->walk_direction = 0;
	else if (keyCode == RIGHT_ARROW)
		mlx->plyr->turn_direction = 0;
	else if (keyCode == LEFT_ARROW)
		mlx->plyr->turn_direction = 0;
	return (0);
}

int	mouse_move(int x, int y, t_mlx *mlx)
{
	if (mlx->ms->x < x)
	{
		key_press(RIGHT_ARROW, mlx);
		key_release(RIGHT_ARROW, mlx);
	}
	else if (mlx->ms->x > x)
	{
		key_press(LEFT_ARROW, mlx);
		key_release(LEFT_ARROW, mlx);
	}
	mlx->ms->x = x;
	if (x < 0 || x > WIN_W || y < 0 || y > WIN_H)
	{
		// mlx_mouse_move(mlx->win, WIN_W / 2, WIN_H / 2);
		mlx->ms->x = 500;
	}
	return (0);
}

int	escp_handler(int keyCode, t_mlx *mlx)
{
	printf("ESC\n");
	exit(0);
}
