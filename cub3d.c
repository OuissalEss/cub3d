/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:56:30 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/10 20:47:49 by slaajour         ###   ########.fr       */
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
			write(2, "Error!\nThe file should be ending by .cub :)\n", 43);
			exit (1);
		}
		i--;
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;

	(void) argv;
	if (argc == 2)
	{
		check_cub(argv[1]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		// write(1, "All good bb\n", 13);
	}
	else
	{
		write(2, "Error!\nNumber of arguments is invalid :)\n", 41);
		exit (1);
	}
}