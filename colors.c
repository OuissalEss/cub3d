/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:37:47 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/16 03:52:23 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	west_check(t_game *game)
{
	game->flag_we++;
	printf("west\n");
}

void	east_check(t_game *game)
{
	(void) game;
	printf("east\n");
}

void	floor_check(t_game *game)
{
	(void) game;
	printf("floor\n");
}

void	ceilling_check(t_game *game)
{
	(void) game;
	printf("ceilling\n");
}
