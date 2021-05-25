#include "cub3d.h"

void	parse_line(t_game *game, char *line, int ret)
{
	char	*pline;

	pline = line;
	while (*pline && *pline <= ' ')
		pline++;
	if (*pline == 'R')
		parse_res(game, pline + 1);
	else if (*pline == 'N' && *(pline +1) == 'O')
		parse_text(game, pline + 2, N); // TODO
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
		i++;
		if (ret == 0)
			break ;
		ret = get_next_line(game->fd, &line);
	}
}
