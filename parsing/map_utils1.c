/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:55:05 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/30 11:43:41 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	new2darr(t_game *game)
{
	// char	**new;
	int		longest;
	int		i;

	longest = longest_line(game);
	i = 0;
	while (game->map_values[i])
		i++;
}
