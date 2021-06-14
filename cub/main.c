#include "cub3d.h"

void	init_game(t_game *game)
{
	game->flag_parse = 0;
	game->screenshot = 0;
	game->moveSpeed = 0.08;
	game->rotSpeed = 0.08;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_esc = 0;
}

int main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc == 3)
		need_screenshot(&game, argv[2]);
	if (argc == 1 || argc > 3)
		error(&game, "error arguments", 0);
	game.mlx = mlx_init();
	parse(&game, argv[1]); //todo
}
