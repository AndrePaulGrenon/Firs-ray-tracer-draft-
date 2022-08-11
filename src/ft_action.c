#include "miniRT.h"

int		color(t_data *img, int i, int j)
{
	t_ray	ray;
	t_vec	dir;
	double	fov;
	t_inter	inter;

	fov = 60 * M_PI / 180;
	dir = vector_c(j - (1080 / 2), i - (1080 / 2), ((-1 * img->w) / 2) * tanf(fov / 2));
	dir.len = length(length2(dir));
	dir = normalized(dir);
	ft_init_ray(&ray, zero_v(), dir);
	//printf("Ray: %f %f %f\n", dir.x, dir.y, dir.z);
	inter = sphere_touch(ray, img->sphere);
	if (inter.hit)
	{
		//printf("inter: %f %f %f\n", inter.n.x, inter.n.y, inter.n.z);
		return (ft_shading(inter, img->sphere, img->ligth));
	}
	return (0x000000);
}

void	loop_ray(t_data *img, int h, int w)
{
	int	i;
	int	j;
	int colour;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			colour = color(img, i, j);
			my_mlx_pixel_put(img, j, i, colour);
			j++;
		}
		i++;
	}
}
