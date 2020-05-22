#include "rtv_1.h"

t_ray	new_ray(t_vec4 orig, t_vec4 direction)
{
	t_ray r;

	r.origin = orig;
	r.direction = direction;
	return (r);
}

t_ray	transform_ray(t_ray r1, t_4x4matrix	*m)
{
	t_ray r2;

	r2.origin = matrix_vec4_multiply(m, r1.origin);
	r2.direction = matrix_vec4_multiply(m, r1.direction);
	free(m);
	return (r2);
}

t_vec4	position(t_ray ray, double t)
{
	t_vec4 pos;

	pos = vec4_multiply_1(ray.direction, t);
	pos = vec4_add(ray.origin, pos);
	return (pos);
}
