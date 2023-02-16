/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:31:02 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/11 05:00:48 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		new[i] = '\n';
		i++;
	}
	new[i - 1] = '\n';
	new[i] = '\0';
	free(mlx->mp->map[x]);
	mlx->mp->map[x] = NULL;
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

t_game	get_map(t_mlx *mlx, char **argv)
{
	int		fd;
	t_game	game;

	check_cub(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	read_file(fd, argv[1], &game);
	both_len(&game);
	both_malloc(&game, argv[1]);
	flags_init(&game);
	check_map_data(&game);
	check_map_values(&game);
	mlx->mp->map = game.map_values;
	mlx->mp->rgb_f = game.rgb_f;
	mlx->mp->rgb_c = game.rgb_c;
	get_height_width(mlx);
	update_map(mlx);
	return (game);
}

void	init_data(t_mlx *mlx)
{
	int		i;

	mlx->plyr = malloc(sizeof(t_player));
	mlx->img = malloc(sizeof(t_img));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_W, WIN_H, "Cub3d");
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img->data = mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
			&mlx->img->size_l, &mlx->img->endian);
	mlx->mp = malloc(sizeof(t_map));
	mlx->ms = malloc(sizeof(t_mouse));
	mlx->ms->x = 500;
	mlx->ray = (t_ray **)malloc(sizeof(t_ray) * NUM_RAYS);
	i = 0;
	while (i < NUM_RAYS)
		mlx->ray[i++] = malloc(sizeof(t_ray));
}
