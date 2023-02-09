/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ndpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:23:14 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/04 03:14:48 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	while (game->map_values[i][j])
	{
		if (game->map_values[i][j] == '\n')
			error_newline();
		if (game->map_values[i][j] != '1' && game->map_values[i][j] != ' ')
			error_wall();
		j++;
	}
}

void	increment(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_values[i])
	{
		j = 0;
		while (game->map_values[i][j])
		{
			if (game->map_values[i][j] == 'E' || game->map_values[i][j] == 'W'
				|| game->map_values[i][j] == 'N'
				|| game->map_values[i][j] == 'S')
				game->var++;
			j++;
		}
		i++;
	}
}

void	one_is_enough(t_game *game)
{
	game->var = 0;
	increment(game);
	if (game->var > 1)
	{
		printf("Error!\nA position here is written more than once :)");
		exit(EXIT_FAILURE);
	}
	if (game->var == 0)
	{
		printf("Error!\nA position is missing :)");
		exit(EXIT_FAILURE);
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
			if (game->map_values[i][j] != '1' && game->map_values[i][j] != '0'
				&& game->map_values[i][j] != 'N'
				&& game->map_values[i][j] != 'S'
				&& game->map_values[i][j] != 'E'
				&& game->map_values[i][j] != 'W'
				&& game->map_values[i][j] != ' '
				&& game->map_values[i][j] != '\n')
			{
				printf("Error!\nSomething added or missing in the map :)");
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
	one_is_enough(game);
	check_wall(game);
	check_space(game);
}
