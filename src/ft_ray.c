#include "miniRT.h"

__attribute((always_inline)) inline t_vec	calculate(t_ray *ray)
{
	return (add(ray->pos, multn(ray->dir, ray->t)));
}

void	ft_init_ray(t_ray *ray, t_vec pos, t_vec direction)
{
	ray->pos = pos;
	ray->dir = normalized(direction);
}
