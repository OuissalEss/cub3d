/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:49:21 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/31 23:09:28 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	surrounding(t_game *game, int i, int j)
{
	if (game->map_values[i][j] == '0' || game->map_values[i][j] == 'N'
			|| game->map_values[i][j] == 'S'
			|| game->map_values[i][j] == 'E'
			|| game->map_values[i][j] == 'W')
	{
		if (if_plus_i(game, i, j))
			error_position();
		if (if_plus_j(game, i, j))
			error_position();
		if (if_minus_j(game, i, j))
			error_position();
		if (if_minus_i(game, i, j))
			error_position();
	}
}

int	longest_line(t_game *game)
{
	int	i;
	int	line;

	line = ft_strlen(game->map_values[0]);
	i = 1;
	while (game->map_values[i])
	{
		if (line >= ft_strlen(game->map_values[i]))
			i++;
		else
			line = ft_strlen(game->map_values[i]);
	}
	return (line);
}

void	check_space(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_values[i])
	{
		j = 0;
		while (game->map_values[i][j])
		{
			surrounding(game, i, j);
			j++;
		}
		i++;
	}
}
