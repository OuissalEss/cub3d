/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:35:55 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/24 21:49:45 by slaajour         ###   ########.fr       */
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
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if ((str[i] >= 32 && str[i] < 48) || (str[i] > 57 && str[i] < 127))
		return (-1);
	return (n * sign);
}

void	colors_error(void)
{
	printf("Error\nSomething is wrong in colors :)!\n");
	exit(EXIT_FAILURE);
}

void	norm(t_game *game)
{
	int		k;
	int		number;

	k = 0;
	while (game->fl_cei[k] != NULL)
	{
		number = ft_atoi(game->fl_cei[k]);
		if (number == -1 || number > 255 || number < 0)
			colors_error();
		k++;
	}
	if ((k - 1) != 2)
		colors_error();
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
		colors_error();
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
