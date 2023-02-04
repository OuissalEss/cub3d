#include "cub3d.h"

// Check if there's a wall at coordinate (x, y)
int	hasWallAt(t_mlx *mlx, double x, double y)
{
	int	mapGridIndexX;
	int	mapGridIndexY;

	mapGridIndexX = (int)floor(x / tail);
	mapGridIndexY = (int)floor(y / tail);
	if (mapGridIndexX < 0 || mapGridIndexX >= mlx->mp->width || mapGridIndexY < 0 || mapGridIndexY >= mlx->mp->height) 
		return (1);
	return (mlx->mp->map[mapGridIndexY][mapGridIndexX] == '1');
}

// Insert pixel into the img buffer
void	put_pixel(t_mlx *mlx, int x, int y, unsigned int color)
{
	int	*dst;

	dst = (int *)(mlx->img->data + (y * mlx->img->size_l + x * (mlx->img->bpp / 8)));
	*dst = color;
}

int	is_valid_playerIdent(t_mlx *mlx, int index)
{
	if (index == N)
		mlx->plyr->rotationAngle = NORTH;
	else if (index == S)
		mlx->plyr->rotationAngle = SOUTH;
	else if (index == E)
		mlx->plyr->rotationAngle = EAST;
	else if (index == W)
		mlx->plyr->rotationAngle = WEST;
	if (index == N || index == S || index == E || index == W)
		return (1);
	return (0);
}

void	draw_f_c(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H / 2)
	{
		j = 0;
		while (j < WIN_W)
		{
			put_pixel(mlx, j, i, mlx->mp->rgb_c);
			j++;
		}
		i++;
	}
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			put_pixel(mlx, j, i, mlx->mp->rgb_f);
			j++;
		}
		i++;
	}
}

void	update_window(t_mlx *mlx)
{
	draw_f_c(mlx);
	update_player(mlx);
	castAllRays(mlx);
	render3DProjectedWalls(mlx->ray, mlx);
	draw_map(mlx);
	draw_player(mlx);
	cast2DRays(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img->img_ptr, 0, 0);
}