/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:05:17 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/10 02:28:59 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parsing/parsing.h"
#include "textures.h"

void	loop(t_mlx *mlx)
{
	update_window(mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 03, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 17, 1L << 5, escp_handler, mlx);
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
