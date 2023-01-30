/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ndpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:23:14 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/30 11:08:58 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sides_map(t_game *game)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (game->map_values[i])
	{
		j = 0;
		len = ft_strlen(game->map_values[i]);
		while (game->map_values[i][j] == ' ')
			j++;
		if (game->map_values[i][j] != '1'
			|| game->map_values[i][len - 2] != '1')
		{
			printf("Error!\n1 is missing in one of the sides :)");
			exit(EXIT_FAILURE);
		}
		i++;
	}
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
	while (game->map_values[i][j])
	{
		if (game->map_values[i][j] == '\n')
			error_newline();
		if (game->map_values[i][j] != '1' && game->map_values[i][j] != ' ')
			error_wall();
		j++;
	}
}

void	empty_line(t_game *game, int i)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (game->map_values[i][j])
	{
		if (game->map_values[i][j] == ' ' || game->map_values[i][j] == '\t')
			count++;
		j++;
	}
	if (count + 1 == ft_strlen(game->map_values[i]))
	{
		printf("Error!\nEmpty line detected :)");
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
		empty_line(game, i);
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
	sides_map(game);
	check_space(game);
	new2darr(game);
}
