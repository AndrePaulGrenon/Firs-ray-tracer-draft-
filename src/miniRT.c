#include "miniRT.h"



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int 	i;
	int 	j;
	int		w;
	int		h;
	int		hexa;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	i = 0;
	j = 0;
	h = 1080;
	w = 1920;
	while(i < w)
	{
		j = 0;
		while (j < h)
		{
			hexa = 0x00000000;
			hexa = (i*255)/w+((((w-i)*255)/w)<<16)+(((j*255)/h)<<8);
			//hexa = hexa + ((i / 16) * 32000);
			my_mlx_pixel_put(&img,  i, j, hexa);
			j++;
		}
		i++;
	}

		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
