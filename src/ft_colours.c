#include "miniRT.h"



double	ft_intensity(t_inter inter, t_shape sphere, t_shape light)
{
	t_vec	to_light;
	double	intensity;
	double	llen;

	if (sphere.type == SPHERE)
	{
		to_light = subs(light.pos, inter.point);
		to_light.len = length(length2(to_light));
		llen = to_light.len;
		to_light = normalized(to_light);
		intensity = (light.i * (dot(to_light, inter.n)))/ (llen * llen);// (to_light.len * to_light.len);
	}
	if (sphere.type == PLANE)
	{
		to_light = subs(light.pos, inter.point);
		to_light.len = length(length2(to_light));
		//to_light = normalized(to_light);
		intensity = light.i /(to_light.len * to_light.len);
	}
	return (intensity);
}

int	ft_shading(t_inter inter, t_shape sphere, t_shape light)
{
	unsigned char trgb[4];
	double	intensity;
	double	reste;

	reste = 0;
	intensity = ft_intensity(inter, sphere, light) + AMBIENT;
	if (intensity < 0)
		intensity = 0;
	else if (intensity > 1)
	{
		reste = (intensity - 1) * (intensity - 1) * 255;
		intensity = 1;
	}
	trgb[0] = 0;
	trgb[1] = (char) min(255, ((reste + sphere.trgb[1]) * intensity));
	trgb[2] = (char) min(255, ((reste + sphere.trgb[2]) * intensity));
	trgb[3] = (char) min(255, ((reste + sphere.trgb[3]) * intensity));
	return (create_trgb(trgb[0], trgb[1], trgb[2], trgb[3]));
}
