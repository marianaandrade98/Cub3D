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


typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

int		main(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif
