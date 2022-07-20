#include "miniRT.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


//Gradient : For full raimbow color, style = 8)
t_data	*ft_gradient(int w, int h, int style, t_data *img)
{
	int 	i;
	int 	j;
	int	hexa;

	i = 0;
	j = 0;
	while(i < w)
	{
		j = 0;
		while (j < h)
		{
			hexa = 0x00000000;
			hexa = (i*255)/w+((((w-i)*255)/w)<<(style * 2)+(((j*255)/h)<<style);
			my_mlx_pixel_put(img,  i, j, hexa);
			j++;
		}
		i++;
	}
	return (img);
}
