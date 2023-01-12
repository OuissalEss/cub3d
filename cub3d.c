/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:56:30 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/11 23:05:50 by slaajour         ###   ########.fr       */
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

char	**read_map(int fd)
{
	char	**splitted_map;
	char	*line;
	char	*map;

	line = ft_strdup("");
	map = get_next_line(fd);
	if (map == NULL)
	{
		printf("Error\nEmpty map :)");
		exit(EXIT_FAILURE);
	}
	while (line != NULL)
	{
		map = ft_strjoin(map, line);
		free (line);
		line = get_next_line(fd);
	}
	splitted_map = ft_split(map, '\n');
	free (map);
	return (splitted_map);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc == 2)
	{
		check_cub(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		game.map = read_map(fd);
		directions(&game);
		// for(int i = 0; i < 23; i++)
		// {
		// 	printf("%s\n", game.map[i]);
		// }
		// write(1, "All good bb\n", 13);
	}
	else
	{
		printf("Error!\nNumber of arguments is invalid :)\n");
		exit(EXIT_FAILURE);
	}
}