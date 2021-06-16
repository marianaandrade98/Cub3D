#include "cub3d.h"

void	creat_bmp(t_game *game)
{
   int  fd;
   int  fz;
   int  i;

   i = 0;
   init_bpm_buf(game);
   fz = 54 + (3 * (game->height_screen * game->width_screen));
   calc(game);
   draw(game);
   draw_rectangles(game); //todo
}

void	init_bpm_buf(t_game *game)
{
	int	i;

	i = 0;
	game->bmp_buf = ft_calloc(game->height_screen, sizeof(int *));
	while (i < game->height_screen)
	{
		game->bmp_buf[i] = ft_calloc(game->width_screen, sizeof(int *));
		i++;
	}
}