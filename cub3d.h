/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaajour <slaajour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:14:36 by slaajour          #+#    #+#             */
/*   Updated: 2023/01/21 04:55:21 by slaajour         ###   ########.fr       */
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

typedef struct s_game{
	char	**map;
	char	**map1;
	char	**map2;
	char	**splitted_map;
	char	*new;
	int		len;
	int		len_map1;
	int		len_map2;
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
int		len_file(char *av);
int		both_len(t_game *game);
void	both_malloc(t_game *game, char *av);

		/* CUB3D UTILS */
char	**ft_split(char const *s, char c);
int		word_length(char *k, int i, char c);
int		word_count(char *l, char c);
char	*ft_strjoin2(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);

		/* DIRECTIONS AND COLORS */
void	flags_init(t_game *game);
void	check_map1(t_game *game);
void	directions(t_game *game, int i, int j);
void	north_check(t_game *game, int i, int j);
void	south_check(t_game *game, int i, int j);
void	west_check(t_game *game, int i, int j);
void	east_check(t_game *game, int i, int j);
void	floor_check(t_game *game, int i, int j);
void	ceilling_check(t_game *game, int i, int j);
void	all_checked(t_game *game);

#endif
