#include "cub3d.h"

t_game	*game_init(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	if (argc > 3)
		error_msg(game, "Arguments??\n");
	else if (argc < 2)
		error_msg(game, "Where is the file?\n");
	else if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub") != 0)
		error_msg(game, "Invalid Ext!\n");
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		error_msg(game, "No file\n");
	parse_file(game); //todo
}
