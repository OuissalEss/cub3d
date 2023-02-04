/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:55:05 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/03 00:35:46 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	if_plus_i(t_game *game, int i, int j)
{
	if (game->map_values[i + 1][j] != '0'
		&& game->map_values[i + 1][j] != '1'
		&& game->map_values[i + 1][j] != 'S'
		&& game->map_values[i + 1][j] != 'E'
		&& game->map_values[i + 1][j] != 'N'
		&& game->map_values[i + 1][j] != 'W')
		return (1);
	else
		return (0);
}

int	if_plus_j(t_game *game, int i, int j)
{
	if (game->map_values[i][j + 1] != '0'
		&& game->map_values[i][j + 1] != '1'
		&& game->map_values[i][j + 1] != 'S'
		&& game->map_values[i][j + 1] != 'E'
		&& game->map_values[i][j + 1] != 'N'
		&& game->map_values[i][j + 1] != 'W')
		return (1);
	else
		return (0);
}

int	if_minus_i(t_game *game, int i, int j)
{
	if (game->map_values[i - 1][j] != '0'
		&& game->map_values[i - 1][j] != '1'
		&&game->map_values[i - 1][j] != 'S'
		&& game->map_values[i - 1][j] != 'E'
		&&game->map_values[i - 1][j] != 'N'
		&& game->map_values[i - 1][j] != 'W')
		return (1);
	else
		return (0);
}

int	if_minus_j(t_game *game, int i, int j)
{
	if (game->map_values[i][j - 1] != '0'
		&& game->map_values[i][j - 1] != '1'
		&&game->map_values[i][j - 1] != 'S'
		&& game->map_values[i][j - 1] != 'E'
		&&game->map_values[i][j - 1] != 'N'
		&& game->map_values[i][j - 1] != 'W')
		return (1);
	else
		return (0);
}
