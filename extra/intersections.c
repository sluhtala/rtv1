#include "rtv_1.h"
#include <stdarg.h>

t_intersection	intersection(double t, t_sphere object)
{
	t_intersection i;

	i.object = object;
	i.t = t;
	return (i);
}

t_intersection	*intersections(int count, ...)
{
	t_intersection	*iptr;
	va_list			ar;
	int				i;

	i = 0;
	if (count == 0)
		return (NULL);
	if (!(iptr = (t_intersection*)malloc(sizeof(t_intersection) * count)))
		error_manager("Malloc error.");
	va_start(ar, count);
	while (i < count)
	{
		iptr[i] = va_arg(ar, t_intersection);
		i++;
	}
	va_end(ar);
	return (iptr);
}

t_intersection *intersect_world(t_world *w, t_ray r)
{
	int i;
	t_intersection *xs;
	t_intersection *temp;

	xs = malloc(sizeof(t_intersection) * w->amount);
	i = 0;
	while (i < w->amount)
	{
		temp = intersect(w->spheres[i], r);
		if (temp)
			xs[i * 2] = temp[0];
		if (temp)
			xs[i * 2 + 1] = temp[1];
		if (temp)
			free(temp);
		i++;
	}
	return (xs);
}

t_intersection *intersect(t_sphere s, t_ray r)
{
	double discriminant;
	t_vec4 sphere_to_ray;
	double abc[3];
	t_inters xs;
	t_ray r2;

	r2 = transform_ray(r, matrix4x4_inverse(s.transform));	
	sphere_to_ray = vec4_substract(r2.origin, new_vec4(0, 0, 0, 1.0));
	abc[0] = vec4_dot(r2.direction, r2.direction);
	abc[1] = 2.0 * vec4_dot(r2.direction, sphere_to_ray);
	abc[2] = vec4_dot(sphere_to_ray, sphere_to_ray) - 1.0;
	discriminant = abc[1] * abc[1] - 4.0 * abc[0] * abc[2];
	if (discriminant < 0)
	{
		xs.count = 0;
		return (NULL);
	}
	xs.count = 2;
	xs.t[0] = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]); 
	xs.t[1] = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);  
	if (xs.t[0] > xs.t[1])
	{
		abc[0] = xs.t[0];
		xs.t[0] = xs.t[1];
		xs.t[1] = abc[0];
	}
	return (intersections(2, intersection(xs.t[0], s), intersection(xs.t[1], s)));
}

t_intersection	hit(t_intersection *iptr)
{
	t_intersection ihit;
	int i;
	int result;

	i = 0;
	result = -1;
	ihit.t = 100000000;
	while (i < 2 && iptr)
	{
		if (iptr[i].t >= 0 && (iptr[i].t < ihit.t))
		{
			result = i;
			ihit = iptr[i];
		}
		i++;	
	}
	if (result == -1)
	{
		ihit.t = -1000;
		return (ihit);
	}
	return (ihit);
}
