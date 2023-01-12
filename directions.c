/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:51:05 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/11 23:19:23 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	directions(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i][0] != '1')
	{
		j = 0;
		while (game->map[i][j] == ' ')
			j++;
		if (game->map[i][j] == 'N' && game->map[i][j + 1] == 'O')
			north_check(game);
		else if (game->map[i][j] == 'S' && game->map[i][j + 1] == 'O')
			south_check(game);
		else if (game->map[i][j] == 'W' && game->map[i][j + 1] == 'E')
			west_check(game);
		else if (game->map[i][j] == 'E' && game->map[i][j + 1] == 'A')
			east_check(game);
		else if (game->map[i][j] == 'F')
			floor_check(game);
		else if (game->map[i][j] == 'C')
			ceilling_check(game);
		else
		{
			printf("Error!\nThere is an error in RGB colors or textures :)\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	while (game->map[i][k] == ' ')
			k++;
}

void	north_check(t_game *game)
{
	int	i;

	i = 0;
	
}

void	south_check(t_game *game)
{
	
}

void	west_check(t_game *game)
{
	
}

void	east_check(t_game *game)
{
	
}
