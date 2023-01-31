/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:35:55 by slaajour          #+#    #+#             */
/*   Updated: 2023/02/01 00:09:48 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(char *str)
{
	int	n;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if ((str[i] >= 32 && str[i] < 48) || (str[i] > 57 && str[i] < 127))
		return (-1);
	return (n * sign);
}

void	norm_floor(t_game *game)
{
	int		k;

	k = 0;
	while (game->floor[k] != NULL)
	{
		game->floor_tab[k] = ft_atoi(game->floor[k]);
		if (game->floor_tab[k] == -1 || game->floor_tab[k] > 255
			|| game->floor_tab[k] < 0)
			error_colors();
		k++;
	}
	if ((k - 1) != 2)
		error_colors();
	game->rgb_f = 0 << 24 | game->floor_tab[0] << 16
		| game->floor_tab[1] << 8 | game->floor_tab[2];
	printf("%u\n", game->rgb_f);
}

void	norm_ceiling(t_game *game)
{
	int		k;

	k = 0;
	while (game->ceiling[k] != NULL)
	{
		game->ceiling_tab[k] = ft_atoi(game->ceiling[k]);
		if (game->ceiling_tab[k] == -1 || game->ceiling_tab[k] > 255
			|| game->ceiling_tab[k] < 0)
			error_colors();
		k++;
	}
	if ((k - 1) != 2)
		error_colors();
	game->rgb_c = 0 << 24 | game->ceiling_tab[0] << 16
		| game->ceiling_tab[1] << 8 | game->ceiling_tab[2];
	printf("%u\n", game->rgb_c);
}

void	semicolon(t_game *game)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (game->string[k])
	{
		if (game->string[k] == ',')
			i++;
		k++;
	}
	if (i > 2 || i < 2)
		error_colors();
}

void	xpm_check(t_game *game, int i, int j)
{
	int		k;
	char	*comp;

	comp = "mpx.";
	while (game->splitted[i][j])
		j++;
	j--;
	k = 0;
	while (comp[k])
	{
		if (game->splitted[i][j] != comp[k])
		{
			printf("Error!\nThe file should be ending by .xpm :)\n");
			exit(EXIT_FAILURE);
		}
		j--;
		k++;
	}	
}
