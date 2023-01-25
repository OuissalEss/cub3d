/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ndmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:23:14 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/25 18:35:50 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_wall(void)
{
	printf("Error!\n1 is missing in the wall :)");
	exit(EXIT_FAILURE);
}

void	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_values[0][i] != '\n')
	{
		if (game->map_values[0][i] != '1' && game->map_values[0][i] != ' ')
			error_wall();
		i++;
	}
	i = 0;
	while (game->map_values[i])
		i++;
	i--;
	j = 0;
	while (game->map_values[i][j] != '\n')
	{
		if (game->map_values[i][j] != '1' && game->map_values[i][j] != ' ')
			error_wall();
		j++;
	}
}

void	sides_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_values[i] != NULL)
	{
		j = 0;
		while (game->map_values[i][j] == ' ')
			j++;
		if (game->map_values[i][j] != '1')
			error_wall();
		i++;
	}
	i = 0;
	while (game->map_values[i] != NULL)
	{
		j = 0;
		while (game->map_values[i][j] != '\n')
			j++;
		if (game->map_values[i][j - 1] != '1')
			error_wall();
		i++;
	}
}

void	all_here(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_values[i])
	{
		j = 0;
		while (game->map_values[i][j])
		{
			printf("%c\n", game->map_values[i][j]);
			printf("i = %d\n", i);
			printf("j = %d\n", j);
			if (game->map_values[i][j] != '1' || game->map_values[i][j] != '0'
				|| game->map_values[i][j] != 'N'
				|| game->map_values[i][j] != 'S'
				|| game->map_values[i][j] != 'E'
				|| game->map_values[i][j] != 'W')
			{
				printf("Error!\nSomething is missing in the map :)");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_map_values(t_game *game)
{
	all_here(game);
	check_wall(game);
	sides_map(game);
}
