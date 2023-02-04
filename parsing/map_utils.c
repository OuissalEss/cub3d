/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:49:21 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/03 00:34:29 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
