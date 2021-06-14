#include "cub3d.h"

void	parse_side(t_game *game, char *line, int i, int side)
{
	int		count;
	int		j;
	char	*texture;

	count = 0;
	j = 0;
	while (ft_isalpha(line[i]) == 0)
		i++;
	while (ft_isalpha(line[i++]) || line[i++] == '.' || line[i++] == '/')
		count++;
	i = 2;
	texture = ft_calloc(count + 1, sizeof(char *));
	
}

t_list	*parse_infos(t_game *game, int fd, t_list *elem)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			parse_screen(game, line, 1);
		else if (line[0] == 'N' && line[1] == 'O')
			parse_side(game, line, 2, 0); //todo
	}
	return (elem);
}

void	parse(t_game *game, char *argv)
{
	int		fd;
	int		i;
	int		x;
	t_list	*elem;

	if (!ft_strstr(argv, ".cub"))
		error(game, "Name file error", 0);
	elem = NULL;
	x = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		msg_error(game, "error open file", 0);
	elem = parse_infos(game, fd, elem); //todo
}