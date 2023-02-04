#include "cub3d.h"

int	key_press(int keyCode, t_mlx *mlx)
{
	if (keyCode == UP_ARROW)
		mlx->plyr->walkDirection = +1;
	else if (keyCode == DOWN_ARROW)
		mlx->plyr->walkDirection = -1;
	else if (keyCode == RIGHT_ARROW)
		mlx->plyr->turnDirection = +1;
	else if (keyCode == LEFT_ARROW)
		mlx->plyr->turnDirection = -1;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_W, WIN_H);
	mlx->img->data = mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp, &mlx->img->size_l,&mlx->img->endian);
	update_window(mlx);
	return (0);
}

int	key_release(int keyCode, t_mlx *mlx)
{
	if (keyCode == UP_ARROW)
		mlx->plyr->walkDirection = 0;
	else if (keyCode == DOWN_ARROW)
		mlx->plyr->walkDirection = 0;
	else if (keyCode == RIGHT_ARROW)
		mlx->plyr->turnDirection = 0;
	else if (keyCode == LEFT_ARROW)
		mlx->plyr->turnDirection = 0;
	return (0);
}

int	escp_handler(int keyCode, t_mlx *mlx)
{
	printf("ESC\n");
	exit(0);
}