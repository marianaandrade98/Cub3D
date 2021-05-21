#include "cub3d.h"

void	error_msg(t_game *game, char *msg)
{
	if (game->error)
		return ;
	write(1, "Error:\n", 7);
	write(1, msg, ft_strlen(msg));
	game->error = 1;
}
