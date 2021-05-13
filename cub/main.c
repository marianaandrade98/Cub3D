#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

	y = 0;
	while (y < 50)
		y++ ;
	//for(y = 0; y < 50; ++y)
	// x = 0;
	// while (++x < 50)
	for(x = 0; x < 50; ++x)
	{
    	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    	*(unsigned int*)dst = color;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);

    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);

    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
