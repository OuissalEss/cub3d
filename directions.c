/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:37:47 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/19 00:05:53 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	west_check(t_game *game, int i, int j)
{
	if (game->flag_we == 0)
	{
		while (game->splitted_map[i][j] == ' ')
			j++;
		game->flag_we++;
	}
	else
	{
		printf("Error\n(WE) here is writen more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}

void	east_check(t_game *game, int i, int j)
{
	if (game->flag_ea == 0)
	{
		while (game->splitted_map[i][j] == ' ')
			j++;
		game->flag_ea++;
	}
	else
	{
		printf("Error\n(EA) here is writen more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}

void	floor_check(t_game *game, int i, int j)
{
	if (game->flag_f == 0)
	{
		while (game->splitted_map[i][j] == ' ')
			j++;
		game->flag_f++;
	}
	else
	{
		printf("Error\n(F) here is writen more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}

void	ceilling_check(t_game *game, int i, int j)
{
	if (game->flag_c == 0)
	{
		while (game->splitted_map[i][j] == ' ')
			j++;
		game->flag_c++;
	}
	else
	{
		printf("Error\n(C) here is writen more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}
