#ifndef CUB3D_H
# define CUB3D_H

//#include <mlx.h>
# include <math.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

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
