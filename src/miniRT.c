#include "miniRT.h"

int	main(int argc, char **argv)
{
	//Image
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	(void) argc;
	(void) argv;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.h = 1080;
	img.w = 1080;
	img.sphere.pos = vector_c(0, 0, -75);
	img.sphere.r = 40;
	img.sphere.trgb[0] = 0;
	img.sphere.trgb[1] = 125;
	img.sphere.trgb[2] = 0;
	img.sphere.trgb[3] = 255;
	img.ligth.pos = vector_c(-50, -95, -30);
	img.ligth.i = 1;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	loop_ray(&img, 1080, 1080);
	/*if (argc == 1)
		ft_gradient(1920, 1080, 8, &img);
	if (argc == 2)
		ft_gradient(1920, 1080, ft_atoi(argv[1]), &img);
		*/
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

}
