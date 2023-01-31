/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:40:36 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/31 22:50:25 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_cub(char *str)
{
	int		i;
	int		j;
	char	*comp;

	comp = "buc.";
	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	while (comp[j])
	{
		if (str[i] != comp[j])
		{
			printf("Error!\nThe file should be ending by .cub :)\n");
			exit(EXIT_FAILURE);
		}
		i--;
		j++;
	}
}

int	len_file(char *av)
{
	int		i;
	char	*str;
	int		ffd;

	ffd = open(av, O_RDONLY);
	str = get_next_line(ffd);
	i = 0;
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(ffd);
	}
	return (i);
}

void	read_file(int fd, char *av, t_game *game)
{
	int		i;

	game->len = len_file(av);
	game->map = malloc(sizeof(char *) * game->len);
	i = 0;
	while (i < game->len)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	if (game->map[i - 1] == NULL)
	{
		printf("Error\nEmpty file :)");
		exit(EXIT_FAILURE);
	}
}

int	both_len(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] == ' ')
			j++;
		if (game->map[i][j] == '1')
		{
			game->len_map_data = i + 1;
			game->len_map_values = game->len - i + 1;
			return (i);
		}
		i++;
	}
	return (0);
}

void	both_malloc(t_game *game, char *av)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	fd = open(av, O_RDONLY);
	game->map_data = malloc(sizeof(char *) * game->len_map_data + 1);
	while (i < game->len_map_data - 1)
	{
		game->map_data[i] = get_next_line(fd);
		i++;
	}
	game->map_data[i] = NULL;
	game->map_values = malloc(sizeof(char *) * game->len_map_values + 1);
	j = 0;
	while (j < game->len_map_values)
	{
		game->map_values[j] = get_next_line(fd);
		j++;
	}
	game->map_values[j] = NULL;
}
