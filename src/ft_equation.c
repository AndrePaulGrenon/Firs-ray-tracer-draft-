#include "miniRT.h"

t_inter	sphere_touch(t_ray ray, t_shape sphere)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	t_inter	inter;

	a = 1;
	b = 2 * dot(ray.dir, subs(ray.pos, sphere.pos));
	c = length2(subs(ray.pos, sphere.pos)) - (sphere.r * sphere.r);
	delta = (b * b) - (4 * a * c);
	inter.hit = false;
	if (delta < 0)
		return (inter);
	t1 = (-b - sqrt(delta)) / (2 * a);
	t2 = (-b + sqrt(delta)) / (2 * a);
	if (t2 < 0)
		return (inter);
	inter.hit = true;
	if (t1 > 0)
		inter.point = add(ray.pos, multn(ray.dir, t1));
	else
		inter.point = add(ray.pos, multn(ray.dir, t2));
	inter.n = subs(inter.point, sphere.pos);
	inter.n.len = length(length2(inter.n));
	inter.n = normalized(inter.n);
	inter.object = sphere;
	//printf("point: %f %f %f\n", inter.n.x, inter.n.y, inter.n.z);
	return (inter);
}

double	plane_equation(t_ray ray, t_shape plane)
{
	double t;
	double dDotN;

	dDotN = dot(ray.dir, plane.n);
	if (dDotN == 0)
		return (0);
	t = dot(subs(plane.pos, ray.pos), plane.n) / dDotN;

	if (t <= RAY_T_MIN)
		return (0);
	return (t);
}

t_inter	plane_touch(t_ray ray, t_shape plane)
{
	t_inter inter;
	double	t;

	t = plane_equation(ray, plane);
	if (t == 0)
	{
		inter.hit = false;
		return (inter);
	}
	inter.hit = true;
	inter.point = add(ray.pos, multn(ray.dir, t));
	inter.n = subs(inter.point, plane.pos);
	inter.n.len = length(length2(inter.n));
	inter.n = normalized(inter.n);
	inter.object = plane;
	return (inter);
}

