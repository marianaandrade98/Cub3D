#include "cub3d.h"

void	parse_line(t_game *game, char *line, int ret)
{
	char	*pline;

	pline = line;
	while (*pline && *pline <= ' ')
		pline++;
	if (*pline == 'R')
		parse_res(game, pline + 1); // todo
}

void	parse_file(t_game *game)
{
	char	*line;
	int		ret;
	int		i;

	i = 1;
	ret = get_next_line(game->fd, &line);
	while (ret >= 0)
	{
		parse_line(game, line, ret); //todo
		free(line);
		ret = get_next_line(game->fd, &line);
	}
}
