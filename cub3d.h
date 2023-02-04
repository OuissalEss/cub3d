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

# define tail 32
# define WIN_H 1000
# define WIN_W 1000

# define FOV_ANGLE (60 * (PI / 180))
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS (WIN_H / WALL_STRIP_WIDTH)

# define scale 0.1254
// # define scale 1

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct s_ray{
	float	rayAngle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int		wasHitVertical;
	int		isRayFacingDown;
	int		isRayFacingUp;
	int		isRayFacingRight;
	int		isRayFacingLeft;
	float	horzWallHitX;
	float	horzWallHitY;
	float	vertWallHitX;
	float	vertWallHitY;
}				t_ray;


typedef struct	s_map
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
	double	turnDirection;
	double	walkDirection; 
	double	rotationAngle;
	double	moveSpeed;
	double	rotationSpeed;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		*img;
	t_player	*plyr;
	t_ray		**ray;
	t_map		*mp;
}				t_mlx;

//		KEY HOOK
int		key_press(int keyCode, t_mlx *mlx);
int		key_release(int keyCode, t_mlx *mlx);
int		escp_handler(int keyCode, t_mlx *mlx);

//		PLAYER
int		is_valid_playerIdent(t_mlx *mlx, int index);
void	draw_player(t_mlx *mlx);
void	update_player(t_mlx *mlx);

//		2D MAP
void	draw_map(t_mlx *mlx);
void	castAllRays(t_mlx *mlx);
void	cast2DRays(t_mlx *mlx);

//		3D
void	render3DProjectedWalls(t_ray** rays, t_mlx *mlx);

//		UTILS
void	update_window(t_mlx *mlx);
void	put_pixel(t_mlx *mlx, int x, int y, unsigned int color);
void	mlx_rectangle(t_mlx *mlx, int x, int y, int width, int height, int r, int g, int b);
int		hasWallAt(t_mlx *mlx, double x, double y);
unsigned int	createRGB(unsigned char r, unsigned char g, unsigned b);

//		PARSING	
// char	*get_next_line(int fd, int *x);
// int		ft_strlen(const char *s);
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char *s1, char *s2);
// int		get_map(const char *file_name, t_mlx *mlx);

#endif