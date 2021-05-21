#ifndef CUB3D_H
# define CUB3D_H

//#include <mlx.h>
# include <math.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR 1

# define SPEED 15
# define TURN 0.05

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define KEY_ESC 53

typedef enum		e_side
{
	N,
	W,
	S,
	E
}					t_side;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
}					t_mlx;

typedef struct		s_text
{
	double			wall_dist;
	double			wall_x;
	int				line_height;
	t_side			side;
}					t_text;

typedef struct		s_sprited
{
	double	transform[2];
	int		x;
	int		size;
	int		i;
}					t_sprited;

typedef struct		s_dda
{
	double			side_dist[2];
	double			delta_dist[2];
	double			wall_dist;
	int				line_height;
	int				map_pos[2];
	int				step[2];
}					t_dda;

typedef struct		s_ctrls
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}					t_ctrls;

typedef struct		s_img
{
	char			*filename;
	void			*ptr;
	int				width;
	int				height;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_sprite
{
	int		pos[2];
	double	distance;
	t_img	texture;
}					t_sprite;

typedef struct		s_game
{
	int				fd;
	int				scr_w;
	int				scr_h;
	int				map_w;
	int				map_h;
	int				nb_pixels;
	double			*z_buffer;
	char			*raw_map;
	char			**char_map;
	int				**map;
	int				color_floor;
	int				color_ceil;
	int				nb_sprites;
	double			pos[2];
	double			dir[2];
	double			cam_plane[2];
	int				fd_save;
	t_mlx			mlx;
	int				color_set[2];
	int				error;
	t_img			textures[4];
	t_sprite		*sprites;
	t_img			sprite_txt;
	t_img			screen;
	t_ctrls			ctrls;
	int				save;
	t_side			cam_dir;
}					t_game;

t_game		*game_init(int argc, char **argv);
void		error_msg(t_game *game, char *msg);
void		parse_file(t_game *game);
void		parse_line(t_game *game, char *line, int ret);
void		parse_res(t_game *game, char *pline);
void		check_res(t_game *game);


//utils
void		*ft_calloc(int count, int size);
int			ft_strcmp(char *s1, char *s2);
int			a2n(char *s);
char		*rmempty(char *pline);

#endif
