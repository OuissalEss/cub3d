/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2ndmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:23:14 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/22 14:03:56 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map2[i] != NULL)
	{
		j = 0;
		while (game->map2[i][j] != '\0')
		{
			while (game->map2[i][j] == ' ')
				j++;
			if ()
			{
				printf("Error\nThere is an empty line in the map :)!\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	check_wall(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map2[i])
	{
		
	}
}