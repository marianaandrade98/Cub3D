#include "cub3d.h"

t_floor	put_floor(t_floor floor, t_game *game)
{
	double	a;
	double	b;

	floor.rayDirX0 = game->dirX - game->planeX;
	floor.rayDirY0 = game->dirY - game->planeY;
	floor.rayDirX1 = game->dirX + game->planeX;
	floor.rayDirY1 = game->dirY + game->planeY;
	floor.p = floor.y - game->height_screen / 2;
	floor.posZ = 0.5 * game->height_screen;
	floor.rowDistance = floor.posZ / floor.p;
	a = (floor.rayDirX1 - floor.rayDirX0);
	b = (floor.rayDirY1 - floor.rayDirY0);
	floor.floorStepX = floor.rowDistance * a / game->width_screen;
	floor.floorStepY = floor.rowDistance * b / game->width_screen;
	floor.floorX = game->posX + floor.rowDistance * floor.rayDirX0;
	floor.floorY = game->posY + floor.rowDistance * floor.rayDirY0;
	return (floor);
}

t_ceil	put_ceil(t_game *game, t_floor *floor, t_ceil ceil)
{
	ceil.ceilX = (int)(floor->floorX);
	ceil.ceilY = (int)(floor->floorY);
	ceil.tx = (int)(WIDTH_T * (floor->floorX - ceil.ceilX)) & (WIDTH_T - 1);
	ceil.ty = (int)(HEIGHT_T * (floor->floorY - ceil.ceilY)) & (HEIGHT_T - 1);
	floor->floorX += floor->floorStepX;
	floor->floorY += floor->floorStepY;
	ceil.floorTexture = 2;
	ceil.color = game->texture[ceil.floorTexture][WIDTH_T * ceil.ty + ceil.tx];
	ceil.color = (ceil.color >> 1) & 8355711;
	game->buf[floor->y][ceil.x] = ceil.color;
	ceil.color = game->texture[5][WIDTH_T * ceil.ty + ceil.tx];
	ceil.color = (ceil.color >> 1) & 8355711;
	game->buf[game->height_screen - floor->y - 1][ceil.x] = ceil.color;
	return (ceil);
}

void	init_wall(t_wall *wall, t_game *game)
{
	wall->cameraX = 2 * wall->x / (double)game->width_screen - 1;
	wall->rayDirX = game->dirX + game->planeX * wall->cameraX;
	wall->rayDirY = game->dirY + game->planeY * wall->cameraX;
	wall->mapX = (int)game->posX;
	wall->mapY = (int)game->posY;
	wall->deltaDistX = fabs(1 / wall->rayDirX);
	wall->deltaDistY = fabs(1 / wall->rayDirY);
	wall->hit = 0;
}

void	steps(t_wall *wall, t_game *game)
{
	if (wall->rayDirX < 0)
	{
		wall->stepX = -1;
		wall->sideDistX = (game->posX - wall->mapX) * wall->deltaDistX;
	}
	else
	{
		wall->stepX = 1;
		wall->sideDistX = (wall->mapX + 1.0 - game->posX) * wall->deltaDistX;
	}
	if (wall->rayDirY < 0)
	{
		wall->stepY = -1;
		wall->sideDistY = (game->posY - wall->mapY) * wall->deltaDistY;
	}
	else
	{
		wall->stepY = 1;
		wall->sideDistY = (wall->mapY + 1.0 - game->posY) * wall->deltaDistY;
	}
	hit_wall(game, wall);
}

void	perp_wall(t_game *game, t_wall *wall)
{
	double	a;
	double	b;

	a = (wall->mapX - game->posX + (1 - wall->stepX) / 2);
	b = (wall->mapY - game->posY + (1 - wall->stepY) / 2);
	if (wall->side == 0 || wall->side == 1)
		wall->perpWallDist = a / wall->rayDirX;
	else
		wall->perpWallDist = b / wall->rayDirY;
	wall->lineHeight = (int)(game->height_screen / wall->perpWallDist);
	wall->drawStart = -wall->lineHeight / 2 + game->height_screen / 2;
	if (wall->drawStart < 0)
		wall->drawStart = 0;
	wall->drawEnd = wall->lineHeight / 2 + game->height_screen / 2;
	if (wall->drawEnd >= game->height_screen)
		wall->drawEnd = game->height_screen - 1;
}
