#ifndef MINI_RT_H
#define MINI_RT_H

# include "../libft/include/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <mlx.h>
# include <math.h>
# include <stdbool.h>

# define COLOR "0123456789ABCDEF"
# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f
# define AMBIENT 0.7f
//#define M_PI 3.14159265359 

typedef struct s_vec
{
	double			x;
	double			y;
	double			z;
	double			len;
	struct s_vec	*norm;

}			t_vec;

typedef struct	s_ray
{
	double	t_max;
	double	t;
	t_vec	pos;
	t_vec	dir;
	t_vec	inter;
}				t_ray;

typedef struct	s_shape
{
	t_vec			pos;
	char			type;
	unsigned char	trgb[4];
	double			i;
	double			r;
}				t_shape;

typedef struct	s_inter
{
	bool	hit;;
	t_vec	point;
	t_vec	n;
}				t_inter;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	t_shape	sphere;
	t_shape	ligth;
	int		h;
	int		w;
}				t_data;

//MLX operations and color tests
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_gradient(int w, int h, int style, t_data *img);

//Number operation
double min(double num1, double num2);
double max(double num1, double num2);

//Vector operations Simple
t_vec	vector_c(double x, double y, double z);
t_vec	zero_v(void);
t_vec	add(t_vec v1, t_vec v2);
t_vec	subs(t_vec v1, t_vec v2);
t_vec	mult(t_vec v1, t_vec v2);
t_vec	divv(t_vec v1, t_vec v2);
t_vec	multn(t_vec v1, double n);
t_vec	divn(t_vec v1, double n);

//Vector Operations Complex
double sqr(double n);
double length(double len2);
double length2(t_vec vec);
double	normalize(t_vec *vec);
double	dot(t_vec v1, t_vec v2);
t_vec	normalized(t_vec vec);
t_vec	cross(t_vec v1, t_vec v2);

//Ray operation
t_vec calculate(t_ray *ray);
void	loop_ray(t_data *img, int h, int w);
void	ft_init_ray(t_ray *ray, t_vec pos, t_vec direction);

//Touch Equation
t_inter	sphere_touch(t_ray ray, t_shape sphere);

//Colours
int	ft_shading(t_inter inter, t_shape sphere, t_shape light);
int	create_trgb(int t, int r, int g, int b);

#endif
