/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:56:30 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/21 05:39:28 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

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
		check_map1(&game);
		// system("leaks cub3D");
	}
	else
	{
		printf("Error!\nNumber of arguments is invalid :)\n");
		exit(EXIT_FAILURE);
	}
}
