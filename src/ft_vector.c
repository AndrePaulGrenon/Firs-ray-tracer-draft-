#include "miniRT.h"

__attribute((always_inline)) inline double sqr(double n)
{
	return (n * n);
}

__attribute((always_inline)) inline double length2(t_vec vec)
{
	return (sqr(vec.x) + sqr(vec.y) + sqr(vec.z));
}

__attribute((always_inline)) inline double length(double len2)
{
	return (sqrt(len2));
}

double	normalize(t_vec *vec)
{
	vec->x = vec->x / vec->len;
	vec->y = vec->y / vec->len;
	vec->z = vec->z / vec->len;
	return (1);
}

t_vec	normalized(t_vec vec)
{
	t_vec n;

	n = vec;
	n.len = normalize(&n);
	return (n);
}
