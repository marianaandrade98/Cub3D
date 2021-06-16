#include "cub3d.h"

void    load_image(t_game *game, int *texture, char *path, t_img *img)
{
    int y;
    int x;

    y = 0;
    img->img = mlx_xpm_file_to_image(game->mlx, path,
            &img->img_width, &img->img_height);
    if ()
}

void    load_texture(t_game *game)
{
    t_img   img;

    load_image //todo
}

int init_buff1(t_game *game)
{
    int i;

    game->texture = ft_calloc(7, sizeof(int *));
    i = -1;
    while (++i < 7)
        game->texture[i] = ft_calloc(HEIGHT_T * WIDTH_T, sizeof(int));
    game->zBuffer = ft_calloc(game->width_screen, sizeof(double *));
	game->buf = ft_calloc(game->height_screen, sizeof(int *));
    i = -1;
    while (++i < game->height_screen)
        game->buf[1] = ft_calloc(game->width_screen, sizeof(int *));
    return (0);
}