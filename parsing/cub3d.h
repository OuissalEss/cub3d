/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:36 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/24 23:30:32 by slaajour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

		/* ONE LOVELY CUTE LONG STRUCT */

typedef struct s_game{
	char	**map;
	char	**map_data;
	char	**map_values;
	char	**splitted;
	char	**fl_cei;
	char	*new;
	char	*string;
	int		len;
	int		len_map_data;
	int		len_map_values;
	int		flag_no;
	int		flag_so;
	int		flag_ea;
	int		flag_we;
	int		flag_f;
	int		flag_c;
}	t_game;

		/* ALLOCATION */
void	check_cub(char *str);
void	read_file(int fd, char *av, t_game *game);
int		both_len(t_game *game);
void	both_malloc(t_game *game, char *av);

		/* CUB3D UTILS */
char	**ft_split(char *s, char c);
char	*ft_strjoin2(char *s1, char *s2);

		/* DIRECTIONS AND COLORS */
void	flags_init(t_game *game);
void	check_map_data(t_game *game);
void	xpm_check(t_game *game, int i, int j);
void	south_check(t_game *game, int i, int j);
void	west_check(t_game *game, int i, int j);
void	east_check(t_game *game, int i, int j);
void	floor_check(t_game *game, int i, int j);
void	ceilling_check(t_game *game, int i, int j);
void	norm(t_game *game);
void	colors_error(void);
void	semicolon(t_game *game);

		/* MAP'S TURN */
void	check_map_values(t_game *game);
#endif
