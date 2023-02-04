/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:05:17 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/04 08:37:45 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing/parsing.h"

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
				put_pixel(mlx, (x + i) * scale, (y + j) * scale,
					createRGB(0, 255, 255));
			j++;
		}
		i++;
	}
}

// Save Initial player position from the config map
void	save_player(t_mlx *mlx)
{
	int	h;
	int	w;

	h = 0;
	while (h < mlx->mp->height)
	{
		w = 0;
		while (w < mlx->mp->width)
		{
			if (is_valid_playerIdent(mlx, mlx->mp->map[h][w]))
			{
				mlx->plyr->x = w * tail + (tail / 2);
				mlx->plyr->y = h * tail + (tail / 2);
			}
			w++;
		}
		h++;
	}
}

// Update the player data on each key press
void	update_player(t_mlx *mlx)
{
	int	move_step;
	int	plyr_x;
	int	plyr_y;

	mlx->plyr->rotationAngle += mlx->plyr->turnDirection * mlx->plyr->rotationSpeed;
	move_step = mlx->plyr->walkDirection * mlx->plyr->moveSpeed;
	plyr_x = mlx->plyr->x + cos(mlx->plyr->rotationAngle) * move_step;
	plyr_y = mlx->plyr->y + sin(mlx->plyr->rotationAngle) * move_step;
	if (!hasWallAt(mlx, plyr_x, plyr_y))
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
			x = w * tail * scale;
			y = h * tail * scale;
			if (mlx->mp->map[h][w] == '1')
				mlx_rectangle(mlx, x, y, scale * tail, scale * tail, 255, 255, 255);
			if (mlx->mp->map[h][w] != '1' && mlx->mp->map[h][w] != ' ' && mlx->mp->map[h][w] != '\n')
				mlx_rectangle(mlx, x, y, scale * tail, scale * tail, 0, 0, 0);
			w++;
		}
		h++;
	}
}

void	init_player(t_player *plyr)
{
	plyr->x = 0;
	plyr->y = 0;
	plyr->radius = 4;
	plyr->turnDirection = 0;
	plyr->walkDirection = 0;
	plyr->rotationAngle = PI / 2;
	plyr->moveSpeed = 10;
	plyr->rotationSpeed = 4 * (PI / 180);
}

// int	get_map(const char *file_name, t_mlx *mlx)
// {
// 	int	fd;
// 	int	i;
// 	int	x;

// 	mlx->mp->map = malloc(sizeof(char *) * (mapWidth + 1));
// 	fd = open(file_name, O_RDONLY);
// 	i = 0;
// 	while (i < mapWidth)
// 	{
// 		mlx->mp->map[i] = get_next_line(fd, &x);
// 		if (mlx->mp->map)
// 			i++;
// 	}
// 	mlx->mp->map[i] = NULL;
// 	return (1);
// }

void	get_height_width(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	mlx->mp->width = 0;
	while (mlx->mp->map[i])
	{
		j = 0;
		while (mlx->mp->map[i][j])
			j++;
		if (mlx->mp->width < j)
			mlx->mp->width = j;
		i++;
	}
	mlx->mp->height = i;
}

void	update_line(t_mlx *mlx, int x)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char) * (mlx->mp->width + 1));
	i = 0;
	while (mlx->mp->map[x][i] && mlx->mp->map[x][i] != '\n')
	{
		new[i] = mlx->mp->map[x][i];
		i++;
	}
	while (i < mlx->mp->width)
	{
		new[i] = ' ';
		i++;
	}
	new[i - 1] = '\n';
	new[i] = '\0';
	free(mlx->mp->map[x]);
	mlx->mp->map[x] = new;
}

void	update_map(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->mp->map[i])
	{
		j = 0;
		while (mlx->mp->map[i][j])
			j++;
		if (j < mlx->mp->width)
			update_line(mlx, i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;
	t_game	game;
	int		count_w;
	int		count_h;

	mlx = malloc(sizeof(t_mlx));
	mlx->plyr = malloc(sizeof(t_player));
	mlx->img = malloc(sizeof(t_img));
	mlx->mp = malloc(sizeof(t_map));
	if (argc == 2)
	{
		check_cub(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		read_file(fd, argv[1], &game);
		both_len(&game);
		both_malloc(&game, argv[1]);
		flags_init(&game);
		check_map_data(&game);
		check_map_values(&game);
	}
	else
	{
		printf("Error!\nNumber of arguments is invalid :)\n");
		exit(EXIT_FAILURE);
	}
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "Cub3d");
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img->data = mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	mlx->mp->map = game.map_values;
	mlx->mp->rgb_f = game.rgb_f;
	mlx->mp->rgb_c = game.rgb_c;
	get_height_width(mlx);
	update_map(mlx);
	init_player(mlx->plyr);
	save_player(mlx);
	update_window(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 03, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 17, 1L << 5, escp_handler, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
