/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 22:37:47 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/21 05:52:33 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	south_check(t_game *game, int i, int j)
{
	int		k;

	if (game->flag_so == 0)
	{
		while (game->splitted_map[i][j + 1] == ' ')
			j++;
		j++;
		k = 0;
		while (j <= ft_strlen(game->splitted_map[i]))
			game->new[k++] = game->splitted_map[i][j++];
		if (access(game->new, F_OK) == -1)
		{
			printf("Error\nThe file xpm doesn't really exist :)!\n");
			exit(EXIT_FAILURE);
		}
		game->flag_so++;
	}
	else
	{
		printf("Error\n(SO) here is written more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}

void	west_check(t_game *game, int i, int j)
{
	int		k;

	if (game->flag_we == 0)
	{
		while (game->splitted_map[i][j + 1] == ' ')
			j++;
		j++;
		k = 0;
		while (j <= ft_strlen(game->splitted_map[i]))
			game->new[k++] = game->splitted_map[i][j++];
		if (access(game->new, F_OK) == -1)
		{
			printf("Error\nThe file xpm doesn't really exist :)!\n");
			exit(EXIT_FAILURE);
		}
		game->flag_we++;
	}
	else
	{
		printf("Error\n(WE) here is written more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}

void	east_check(t_game *game, int i, int j)
{
	int		k;

	if (game->flag_ea == 0)
	{
		while (game->splitted_map[i][j + 1] == ' ')
			j++;
		j++;
		k = 0;
		while (j <= ft_strlen(game->splitted_map[i]))
			game->new[k++] = game->splitted_map[i][j++];
		if (access(game->new, F_OK) == -1)
		{
			printf("Error\nThe file xpm doesn't really exist :)!\n");
			exit(EXIT_FAILURE);
		}
		game->flag_ea++;
	}
	else
	{
		printf("Error\n(EA) here is written more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}

void	floor_check(t_game *game, int i, int j)
{
	int	k;

	if (game->flag_f == 0)
	{
		while (game->splitted_map[i][j + 1] == ' ')
			j++;
		j++;
		printf("%c\n", game->splitted_map[i][j]);
		k = 0;
		printf("%s", game->new);
		while (j <= ft_strlen(game->splitted_map[i]))
		{
			game->new[k++] = game->splitted_map[i][j++];
			printf("%c", game->new[k]);
		}
		game->flag_f++;
	}
	else
	{
		printf("Error\n(F) here is written more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}

void	ceilling_check(t_game *game, int i, int j)
{
	if (game->flag_c == 0)
	{
		while (game->splitted_map[i][j + 1] == ' ')
			j++;
		j++;
		game->flag_c++;
	}
	else
	{
		printf("Error\n(C) here is written more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}
