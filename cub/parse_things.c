#include "cub3d.h"

void	check_res(t_game *game)
{
	if (game->scr_w > 2560)
		game->scr_w = 2560;
	else if (game->scr_w < 800)
		game->scr_w = 800;
	if (game->scr_h > 1440)
		game->scr_h = 1440;
	else if (game->scr_h < 480)
		game->scr_h = 480;
}

/*
** It will ignore the spaces and parse the Resolution
*/

void	parse_res(t_game *game, char *pline)
{
	if (game->scr_w)
		error_msg(game, "Already found Resolution!\n");
	while (*pline <= ' ')
		pline++;
	game->scr_w = a2n(pline);
	while (*pline >= '0' && *pline <= '9')
		pline++;
	while (*pline <= ' ')
		pline++;
	game->scr_h = a2n(pline);
	while (*pline >= '0' && *pline <= '9')
		pline++;
	if (game->scr_w < 0 || game->scr_h < 0)
		error_msg(game, "OVERFLOW!\n");
	pline = rmempty(pline);
	if (game->scr_h == 0 || game->scr_w == 0 || ft_strlen(pline) > 0)
		error_msg(game, "Found no Resolution\n");
	check_res(game);
	free(pline);
}

void	parse_text(t_game *game, char *pline, int text)
{
	t_img	*texture;

	if (text == 4 && game->sprite_txt.filename)
		error_msg(game, "Do not write the sprite texture twice!\n");
}
