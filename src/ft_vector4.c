#include "miniRT.h"

t_vec	multn(t_vec v1, double n)
{
	t_vec v;

	v.x = v1.x * n;
	v.y = v1.y * n;
	v.z = v1.z * n;
	return (v);
}

t_vec	divn(t_vec v1, double n)
{
	t_vec v;

	v.x = v1.x / n;
	v.y = v1.y / n;
	v.z = v1.z / n;
	return (v);
}

