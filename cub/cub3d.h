#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include "key_macos.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# define WIDTH_T 64
# define HEIGHT_T 64

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_game
{	
	int		flag_player;
	int		flag_parse;
	char	buff[4];
	char	buff2[4];
	char	buff3[4];
	int		**bmp_buf;
	char	*tex_south;
	char	*tex_north;
	char	*tex_east;
	char	*tex_west;
	char	*tex_sprite;
	int		minimap_size;
	int		floor_color;
	int		ceil_color;
	int		screenshot;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_esc;
	int		width_screen;
	int		height_screen;
	int		map_size;
	int		numsprites;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	int		**buf;
	int		**texture;
	double	*zBuffer;
	double	moveSpeed;
	double	rotSpeed;
	double	sprite_posy;
	double	sprite_posx;
	char	**map;
}				t_game;

typedef struct s_floor
{
	float	rayDirX0;
	float	rayDirY0;
	float	rayDirX1;
	float	rayDirY1;
	int		p;
	float	posZ;
	float	rowDistance;
	float	floorStepX;
	float	floorStepY;
	float	floorY;
	float	floorX;
	int		y;
}				t_floor;

typedef struct s_ceil
{
	int	x;
	int	ceilX;
	int	ceilY;
	int	tx;
	int	ty;
	int	floorTexture;
	int	ceilingTexture;
	int	color;
}				t_ceil;

typedef struct s_wall
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	int		x;
	int		y;
	double	sideDistX;
	double	sideDistY;
	double	perpWallDist;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double	floorXWall;
	double	floorYWall;
}				t_wall;

typedef struct s_textures
{
	int		texX;
	int		texNum;
	double	wallX;
	double	step;
	double	texPos;
	int		texY;
	int		color;
	int		floorTexture;
	int		y;
}			t_textures;

typedef struct s_sprite
{
	double	y;
	double	x;
	int		texture;
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;
	double	transformY;
	int		spriteScreenX;
	int		vMoveScreen;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		stripe;
	int		d;
	int		texX;
	int		texY;
	int		color;
	int		j;
}			t_sprite;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void	init_map(t_game *game);
void	draw(t_game *game);
t_floor	put_floor(t_floor floor, t_game *game);
t_ceil	put_ceil(t_game *game, t_floor *floor, t_ceil ceil);
void	init_wall(t_wall *wall, t_game *game);
void	steps(t_wall *wall, t_game *game);
void	perp_wall(t_game *game, t_wall *wall);
void	textures_wall(t_wall *wall, t_textures *textures, t_game *game);
void	draw_wall(t_game *game, t_textures *textures, t_wall *wall);
void	load_image(t_game *game, int *texture, char *path, t_img *img);
void	load_texture(t_game *game);
void	draw_rectangle(t_game *game, int x, int y, int color);
void	draw_rectangles(t_game *game);
void	draw_sprite(t_game *game, double pos_x, double pos_y);
char	*ft_itoa(int n);
int		key_release(int key, t_game *game);
int		key_press(int key, t_game *game);
int		key_move(t_game *game);
void	parse(t_game *game, char *argv);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
void	parse_side(t_game *game, char *line, int i, int side);
int		ft_isdigit(int c);
int		create_trgb(int r, int g, int b);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *str);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	parse_map(t_game *game);
void	check_map(t_game *game, int size_map);
void	player_init(t_game *game);
int		ismap(char c);
void	calc(t_game *game);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	init_bpm_buf(t_game *game);
void	draw_all(t_game *game);
void	hit_wall(t_game *game, t_wall *wall);
void	set_int_in_char(unsigned char *start, int value);
int		write_bmp_header(int fd, int filesize, t_game *game);
int		write_bmp_data(int file, t_game *game);
int		init_buff1(t_game *game);
void	creat_bmp(t_game *game);
void	*ft_calloc(size_t count, size_t size);
void	msg_error(t_game *game, char *str, int map_free);
void	chose_side(t_game *game, int side, char *texture);
void	ceil_or_floor(t_game *game, int type);
int		check_start_map(t_game *game);
int		ft_strstr(const char *s1, const char *s2);
void	screen_error(t_game *game);
int		check_all_map(char c);
void	parse_screen(t_game *game, char *line, int i);
void	free_map(t_game *game);
void	free_buffs(t_game *game);
int		exit_game(t_game *game);
void	need_screenshot(t_game *game, char *argv);

#endif