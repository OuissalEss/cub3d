/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:05:17 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/09 04:19:54 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing/parsing.h"
#include "textures.h"

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

// Update the player data on each key press
void	update_player(t_mlx *mlx)
{
	int	move_step;
	int	plyr_x;
	int	plyr_y;

	mlx->plyr->rotation_angle += mlx->plyr->turn_direction
		* mlx->plyr->rotation_speed;
	move_step = mlx->plyr->walk_direction * mlx->plyr->move_speed;
	plyr_x = mlx->plyr->x + cos(mlx->plyr->rotation_angle) * move_step;
	plyr_y = mlx->plyr->y + sin(mlx->plyr->rotation_angle) * move_step;
	if (!has_wall_at(mlx, plyr_x, plyr_y))
	{
		mlx->plyr->x = plyr_x;
		mlx->plyr->y = plyr_y;
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
				mlx_rectangle(mlx, x, y, SCALE * TAIL, SCALE * TAIL,
					255, 255, 255);
			else if (mlx->mp->map[h][w] == 'D')
				mlx_rectangle(mlx, x, y, SCALE * TAIL, SCALE * TAIL, 0, 250, 0);
			else if (mlx->mp->map[h][w] != ' ' && mlx->mp->map[h][w] != '\n')
				mlx_rectangle(mlx, x, y, SCALE * TAIL, SCALE * TAIL, 0, 0, 0);
			w++;
		}
		h++;
	}
}

void	loop(t_mlx *mlx)
{
	update_window(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 03, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 17, 1L << 5, escp_handler, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_game	game;

	if (argc != 2)
	{
		printf("Error!\nNumber of arguments is invalid :)\n");
		exit(EXIT_FAILURE);
	}
	mlx = malloc(sizeof(t_mlx));
	init_data(mlx);
	game = get_map(mlx, argv);
	get_textures(mlx, &game);
	init_player(mlx);
	loop(mlx);
	return (0);
}
