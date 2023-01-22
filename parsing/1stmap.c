/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1stmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:51:05 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/21 05:51:08 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map1(t_game *game)
{
	char	*line;
	char	*new_map;
	int		i;
	int		j;

	i = 0;
	line = ft_strdup("");
	new_map = NULL;
	while (line != NULL)
	{
		new_map = ft_strjoin2(new_map, line);
		line = game->map1[i];
		i++;
	}
	game->splitted_map = ft_split(new_map, '\n');
	free(new_map);
	i = -1;
	while (game->splitted_map[++i])
	{
		j = 0;
		while (game->splitted_map[i][j] == ' ')
			j++;
		directions(game, i, j);
	}
	all_checked(game);
}

void	flags_init(t_game *game)
{
	game->flag_no = 0;
	game->flag_so = 0;
	game->flag_ea = 0;
	game->flag_we = 0;
	game->flag_f = 0;
	game->flag_c = 0;
}

void	all_checked(t_game *game)
{
	if (game->flag_no == 0 || game->flag_so == 0 || game->flag_ea == 0
		|| game->flag_we == 0 || game->flag_f == 0 || game->flag_c == 0)
	{
		printf("Error!\nSomething is missing :)\n");
		exit(EXIT_FAILURE);
	}
}

void	directions(t_game *game, int i, int j)
{
	game->new = malloc(sizeof(char) * ft_strlen(game->splitted_map[i]) + 1);
	if (game->splitted_map[i][j] == 'N' && game->splitted_map[i][j + 1] == 'O')
		north_check(game, i, j + 1);
	else if (game->splitted_map[i][j] == 'S'
		&& game->splitted_map[i][j + 1] == 'O')
		south_check(game, i, j + 1);
	else if (game->splitted_map[i][j] == 'W'
		&& game->splitted_map[i][j + 1] == 'E')
		west_check(game, i, j + 1);
	else if (game->splitted_map[i][j] == 'E'
		&& game->splitted_map[i][j + 1] == 'A')
		east_check(game, i, j + 1);
	else if (game->splitted_map[i][j] == 'F')
		floor_check(game, i, j + 1);
	else if (game->splitted_map[i][j] == 'C')
		ceilling_check(game, i, j + 1);
	else if (game->splitted_map[i][j] == '\0')
		return ;
	else
	{
		printf("Error!\nThere is an error in RGB colors or textures :)\n");
		exit(EXIT_FAILURE);
	}
	free(game->new);
}

void	north_check(t_game *game, int i, int j)
{
	int		k;

	if (game->flag_no == 0)
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
		game->flag_no++;
	}
	else
	{
		printf("Error\n(NO) here is written more than once :)!\n");
		exit(EXIT_FAILURE);
	}
}
