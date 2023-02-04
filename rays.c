#include "cub3d.h"

float	normalizeAngle(float angle)
{
	while (angle < 0)
		angle += 2 * M_PI;
	while (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

t_ray	*createRay(float rayAngle)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->rayAngle = normalizeAngle(rayAngle);
	ray->wallHitX = 0;
	ray->wallHitY = 0;
	ray->distance = 0;
	ray->wasHitVertical = 0;
	ray->isRayFacingDown = ray->rayAngle > 0 && ray->rayAngle < M_PI;
	ray->isRayFacingUp = !ray->isRayFacingDown;
	ray->isRayFacingRight = ray->rayAngle < 0.5 * M_PI || ray->rayAngle > 1.5 * M_PI;
	ray->isRayFacingLeft = !ray->isRayFacingRight;
	return (ray);
}

// Cast the 2d rays
void	cast2DRays(t_mlx *mlx)
{
	int		i;
	int		columnId;
	float	rayAngle;

	columnId = 0;
	rayAngle = mlx->plyr->rotationAngle  - (FOV_ANGLE / 2);
	while (i < NUM_RAYS) 
	{
		rayAngle = normalizeAngle(rayAngle);
		rayAngle+= (FOV_ANGLE / NUM_RAYS);
		columnId++;
		i++;
	}
}

float	distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	float xDiff;
	float yDiff;

	xDiff = x2 - x1;
	yDiff = y2 - y1;
	return sqrt((xDiff * xDiff) + (yDiff * yDiff));
}

// Horizontal Ray-Grid Intersection Code
int	found_horz_wall(t_mlx *mlx, int index)
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

	yintercept = (int)(mlx->plyr->y / tail) * tail;
	if (mlx->ray[index]->isRayFacingDown)
		yintercept += tail;
	xintercept = mlx->plyr->x + (yintercept - mlx->plyr->y) / tan(mlx->ray[index]->rayAngle);
	ystep = tail;
	if (mlx->ray[index]->isRayFacingUp)
		ystep *= - 1;
	xstep = tail / tan(mlx->ray[index]->rayAngle);
	if ((mlx->ray[index]->isRayFacingLeft && xstep > 0) || (mlx->ray[index]->isRayFacingRight && xstep < 0))
		xstep *=  - 1;
	while (xintercept >= 0 && xintercept <= WIN_W && yintercept >= 0 && yintercept <= WIN_H)
	{
		if (hasWallAt(mlx, xintercept, yintercept - (mlx->ray[index]->isRayFacingUp ? 1 : 0)))
		{
			mlx->ray[index]->horzWallHitX = xintercept;
			mlx->ray[index]->horzWallHitY = yintercept;
			return (1);
		}
		else
		{
			xintercept += xstep;
			yintercept += ystep;
		}
	}
	return (0);
}

// Vertical Ray-Grid Intersection Code
int	found_vert_wall(t_mlx *mlx, int index)
{
	float	nextVertTouchX;
	float	nextVertTouchY;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;

	xintercept = (int)(mlx->plyr->x / tail) * tail;
	if (mlx->ray[index]->isRayFacingRight)
		xintercept += tail;
	yintercept = mlx->plyr->y + (xintercept - mlx->plyr->x) * tan(mlx->ray[index]->rayAngle);
	xstep = tail;
	xstep *= mlx->ray[index]->isRayFacingLeft ? -1 : 1;
	ystep = tail * tan(mlx->ray[index]->rayAngle);
	ystep *= (mlx->ray[index]->isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (mlx->ray[index]->isRayFacingDown && ystep < 0) ? -1 : 1;
	nextVertTouchX = xintercept;
	nextVertTouchY = yintercept;
	while (nextVertTouchX >= 0 && nextVertTouchX <= WIN_W && nextVertTouchY >= 0 && nextVertTouchY <= WIN_H)
	{
		if (hasWallAt(mlx, nextVertTouchX - (mlx->ray[index]->isRayFacingLeft ? 1 : 0), nextVertTouchY))
		{
			mlx->ray[index]->vertWallHitX = nextVertTouchX;
			mlx->ray[index]->vertWallHitY = nextVertTouchY;
			return (1);
		}
		else
		{
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}
	}
	return (0);
}

void	cast(t_mlx *mlx, int index) 
{
	float	horzHitDistance;
	float	vertHitDistance;

	horzHitDistance = INT_MAX;
	if (found_horz_wall(mlx, index) == 1)
		horzHitDistance = distanceBetweenPoints(mlx->plyr->x, mlx->plyr->y, mlx->ray[index]->horzWallHitX, mlx->ray[index]->horzWallHitY);
	vertHitDistance = INT_MAX;
	if (found_vert_wall(mlx, index) == 1)
		vertHitDistance = distanceBetweenPoints(mlx->plyr->x, mlx->plyr->y, mlx->ray[index]->vertWallHitX, mlx->ray[index]->vertWallHitY);
	if (horzHitDistance < vertHitDistance)
	{
		mlx->ray[index]->wallHitX = mlx->ray[index]->horzWallHitX;
		mlx->ray[index]->wallHitY = mlx->ray[index]->horzWallHitY;
		mlx->ray[index]->distance = horzHitDistance;
		mlx->ray[index]->wasHitVertical = 0;
	}
	else
	{
		mlx->ray[index]->wallHitX = mlx->ray[index]->vertWallHitX;
		mlx->ray[index]->wallHitY = mlx->ray[index]->vertWallHitY;
		mlx->ray[index]->distance = vertHitDistance;
		mlx->ray[index]->wasHitVertical = 1;
	}
}

unsigned int	createRGB(unsigned char r, unsigned char g, unsigned b)
{
	return ((r << 16) | (g << 8) | b);
}

void	mlx_rectangle(t_mlx *mlx, int x, int y, int width, int height, int r, int g, int b)
{
	int	i;
	int	j;

	i = x;
	while (i < x + width)
	{
		j = y;
		while (j < y + height)
		{
			if (i >= 0 && i < WIN_W && j >= 0 && j < WIN_H)
				put_pixel(mlx, i, j, createRGB(r, g, b));
			j++;
		}
		i++;
	}
}

void	render3DProjectedWalls(t_ray** rays, t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;
	t_ray	*ray;
	float	wallStripHeight;

	i = 0;
	while (i < NUM_RAYS)
	{
		ray = rays[i];
		wallStripHeight = (tail / (ray->distance * cos(ray->rayAngle - mlx->plyr->rotationAngle))) * ((WIN_W / 2) / tan(FOV_ANGLE / 2));
		x = i * WALL_STRIP_WIDTH;
		y = (WIN_H / 2) - (wallStripHeight / 2);
		if (ray->wasHitVertical)
		{
			if (ray->rayAngle > (PI / 2) && ray->rayAngle < (3 * PI / 2))
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wallStripHeight, 0, 0, 255);
			else
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wallStripHeight, 0, 255, 255);
		}
		else
		{
			if (ray->rayAngle > 0 && ray->rayAngle < PI)
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wallStripHeight, 153, 0, 153);
			else
				mlx_rectangle(mlx, x, y, WALL_STRIP_WIDTH, (int)wallStripHeight, 255, 0, 255);
		}
		i++;
	}
}


void	castAllRays(t_mlx *mlx)
{
	int		i;
	float	rayAngle;

	mlx->ray = (t_ray **)malloc(sizeof(t_ray) * NUM_RAYS);
	rayAngle = mlx->plyr->rotationAngle  - (FOV_ANGLE/2);
	if (!mlx->ray)
		return ;
	i = 0;
	while (i < NUM_RAYS) 
	{
		mlx->ray[i] = createRay(rayAngle);
		if (!mlx->ray[i])
			return ;
		cast(mlx, i);
		rayAngle += (FOV_ANGLE / NUM_RAYS);
		i++;
	}
}