#ifndef MINI_RT_H
#define MINI_RT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <mlx.h>

#define COLOR "0123456789ABCDEF"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
