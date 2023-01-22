/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 03:35:55 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/22 09:49:03 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	norm(t_game *game)
{
	int		k;
	int		number;

	k = 0;
	while (game->fl_cei[k] != NULL)
	{
		number = ft_atoi(game->fl_cei[k]);
		if (number == -1 || number > 255 || number < 0 || k > 2)
		{
			printf("Error\nSomething is wrong in colors :)!\n");
			exit(EXIT_FAILURE);
		}
		k++;
	}
}

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
