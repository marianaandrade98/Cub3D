#include "cub3d.h"

void	chose_side(t_game *game, int side, char *texture)
{
    if (side == 0)
		game->tex_north = ft_strdup(texture);
	if (side == 1)
		game->tex_south = ft_strdup(texture);
	if (side == 2)
		game->tex_east = ft_strdup(texture);
	if (side == 3)
		game->tex_west = ft_strdup(texture);
	if (side == 4)
		game->tex_sprite = ft_strdup(texture);
	game->flag_parse += 1;
}

void	check_left_borders(t_game *game, int x, int j)
{
	int	k;

	if (!(ismap(game->map[x][j])))
		error(game, "Map", 1);
	if (game->map[x][j] == ' ')
	{
		k = 0;
		while (game->map[x][k] == ' ')
			k++;
		if (game->map[x][k] != '1')
			error(game, "Map", 1);
	}
}

void	check_map(t_game *game, int size_map)
{
    int	x;
	int	j;

	x = 0;
	j = 0;
	if (game->flag_parse != 8)
		msg_error(game, "Need more arguments in parse file", 1);
    while (x < size_map)
    {
        j = 0;
        while (j < ft_strlen(game->map[x]))
        {
            if (x == check_start_map(game) || j == 0)
                check_left_borders(game, x, j);
            
        }
    }
}