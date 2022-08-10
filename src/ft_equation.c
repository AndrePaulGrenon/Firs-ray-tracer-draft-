#include "miniRT.h"

bool	sphere_touch(t_ray ray, t_shape sphere)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;

	a = 1;
	b = 2 * dot(ray.dir, subs(ray.pos, sphere.pos));
	c = length2(subs(ray.pos, sphere.pos)) - (sphere.r * sphere.r);
	delta = (b * b) - (4 * a * c);
	if (delta < 0)
		return (false);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t2 > 0)
		return (true);
	return (false);
}
