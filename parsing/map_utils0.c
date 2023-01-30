/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:49:21 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/30 11:10:00 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	increment(t_game *game, t_var *var)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_values[i])
	{
		j = 0;
		while (game->map_values[i][j])
		{
			if (game->map_values[i][j] == 'E')
				var->var_e++;
			else if (game->map_values[i][j] == 'W')
				var->var_w++;
			else if (game->map_values[i][j] == 'N')
				var->var_n++;
			else if (game->map_values[i][j] == 'S')
				var->var_s++;
			j++;
		}
		i++;
	}
}

void	one_is_enough(t_game *game)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->var_e = 0;
	var->var_w = 0;
	var->var_s = 0;
	var->var_n = 0;
	increment(game, var);
	if (var->var_e > 1 || var->var_n > 1
		|| var->var_s > 1 || var->var_w > 1)
	{
		printf("Error!\nA position here is written more than once :)");
		exit(EXIT_FAILURE);
	}
	if (var->var_e == 0 && var->var_n == 0
		&& var->var_s == 0 && var->var_w == 0)
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
		if (game->map_values[i][j - 1] == ' '
			|| game->map_values[i][j + 1] == ' '
			|| game->map_values[i - 1][j] == ' '
			|| game->map_values[i + 1][j] == ' ')
		{
			printf("Error!\nUnnecessary space in the map :)");
			exit(EXIT_FAILURE);
		}
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
