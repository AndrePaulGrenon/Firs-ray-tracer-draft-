#include "miniRT.h"

t_ray	reverse_ray(t_ray ray, t_shape cylindre)
{
	t_ray new_ray;

	new_ray.pos = subs(ray.pos, cylindre.pos);
	new_ray.dir = ray.dir; 

	return (new_ray);
}

t_inter	cylindre_touch(t_ray ray, t_shape cylindre)
{
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	double	numSQRT;
	t_inter	inter;
	t_ray	r;

	r = reverse_ray(ray, cylindre);
	inter.hit = false;
	a = (r.dir.x * r.dir.x) + (r.dir.y * r.dir.y);
	b = 2 * ((r.pos.x * r.dir.x) + (r.pos.y * r.dir.y));
	c = (r.pos.x * r.pos.x) + (r.pos.y * r.pos.y) - cylindre.r;
	numSQRT = sqrt((b * b) - 4 * a * c);
	t1 = (((-1) * b) - numSQRT) / (2 * a); 
	t2 = (((-1) * b) + numSQRT) / (2 * a);
	

	if (fabs(ray.dir.z * t1) <= 1 || abs(ray.dir.z * t2 <= 1))
	{	
		printf("t1: %f t2: %f \n", t1, t2);
		inter.hit = true;
	}
	//else
	//	inter.hit = true;
	return (inter);

}
