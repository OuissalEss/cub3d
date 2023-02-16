/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1stpart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:51:05 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/11 05:02:30 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	north_check(t_game *game, int i, int j)
{
	int		k;

	xpm_check(game, i, j);
	if (game->flag_no == 0)
	{
		while (game->splitted[i][j + 1] == ' ')
			j++;
		j++;
		k = 0;
		while (j <= ft_strlen(game->splitted[i]))
			game->new[k++] = game->splitted[i][j++];
		game->no = game->new;
		if (access(game->new, F_OK) == -1)
		{
			printf("Error!\nThe file xpm doesn't really exist :)\n");
			exit(EXIT_FAILURE);
		}
		game->flag_no++;
	}
	else
	{
		printf("Error!\n(NO) here is written more than once :)\n");
		exit(EXIT_FAILURE);
	}
}

void	directions(t_game *game, int i, int j)
{
	char	**s;

	s = game->splitted;
	game->new = malloc(sizeof(char) * ft_strlen(game->splitted[i]) + 1);
	if (s[i][j] == 'N' && s[i][j + 1] == 'O' && s[i][j + 2] == ' ')
		north_check(game, i, j + 1);
	else if (s[i][j] == 'S' && s[i][j + 1] == 'O' && s[i][j + 2] == ' ')
		south_check(game, i, j + 1);
	else if (s[i][j] == 'W' && s[i][j + 1] == 'E' && s[i][j + 2] == ' ')
		west_check(game, i, j + 1);
	else if (s[i][j] == 'E' && s[i][j + 1] == 'A' && s[i][j + 2] == ' ')
		east_check(game, i, j + 1);
	else if (s[i][j] == 'F' && s[i][j + 1] == ' ')
		floor_check(game, i, j + 1);
	else if (s[i][j] == 'C' && s[i][j + 1] == ' ')
		ceilling_check(game, i, j + 1);
	else if (s[i][j] == 'D' && s[i][j + 1] == ' ')
		door_check(game, i, j + 1);
	else if (s[i][j] == '\0')
		return ;
	else
	{
		printf("Error!\nThere is an error in RGB colors or textures or map :)\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map_data(t_game *game)
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
		line = game->map_data[i];
		i++;
	}
	game->splitted = ft_split(new_map, '\n');
	free(new_map);
	i = -1;
	while (game->splitted[++i])
	{
		j = 0;
		while (game->splitted[i][j] == ' ')
			j++;
		directions(game, i, j);
	}
	all_checked(game);
}
