/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessamdi <oessamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:01:17 by oessamdi          #+#    #+#             */
/*   Updated: 2023/02/05 09:36:58 by oessamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define PI 3.14159265

# define SOUTH 1.5708
# define EAST 0
# define NORTH 4.71239
# define WEST 3.14159

# define N 'N'
# define E 'E'
# define S 'S'
# define W 'W'

# define UP_ARROW 126
# define DOWN_ARROW 125
# define RIGHT_ARROW 124
# define LEFT_ARROW 123

# define TAIL 32
# define MAPWIDTH 24
# define MAPHEIGHT 24

// # define WIN_H (mapHeight * TAIL)
// # define WIN_W (mapWidth * TAIL)

# define WIN_H 1000
# define WIN_W 1000

# define FOV_ANGLE (60 * (PI / 180))
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS (WIN_H / WALL_STRIP_WIDTH)

# define SCALE 0.1254
// # define SCALE 1

# include "parsing/parsing.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_ray{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	float	horz_wall_hit_x;
	float	horz_wall_hit_y;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
}				t_ray;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
	unsigned int	rgb_f;
	unsigned int	rgb_c;
}				t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	radius;
	double	turn_direction;
	double	walk_direction;
	double	rotation_angle;
	double	move_speed;
	double	rotation_speed;
}				t_player;

typedef struct s_mouse
{
	int	x;
	int	y;
}				t_mouse;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		*img;
	t_player	*plyr;
	t_ray		**ray;
	t_map		*mp;
	t_mouse		*ms;
}				t_mlx;

//		INIT
void	init_data(t_mlx *mlx);
t_game	get_map(t_mlx *mlx, char **argv);

//		KEY HOOK
int		key_press(int keyCode, t_mlx *mlx);
int		key_release(int keyCode, t_mlx *mlx);
int		escp_handler(int keyCode, t_mlx *mlx);
int		mouse_move(int x, int y, t_mlx *mlx);

//		PLAYER
int		is_valid_playerIdent(t_mlx *mlx, int index);
void	draw_player(t_mlx *mlx);
void	update_player(t_mlx *mlx);

//		2D MAP
void	draw_map(t_mlx *mlx);
void	cast_all_rays(t_mlx *mlx);
void	cast_2d_rays(t_mlx *mlx);
void	cast(t_mlx *mlx, int index);

//		3D
void	render_3d_projected_walls(t_ray **rays, t_mlx *mlx);

//		UTILS
void	update_window(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int x, int y, unsigned int color);
void	mlx_rectangle(t_mlx *mlx, int x, int y, int width, int height, int r, int g, int b);
int		has_wall_at(t_mlx *mlx, double x, double y);
float	distance_between_points(float x1, float y1, float x2, float y2);

//		PLAYER
int		is_valid_player_id(t_mlx *mlx, int index);
void	player_position(t_mlx *mlx);
void	init_player(t_mlx *mlx);

#endif