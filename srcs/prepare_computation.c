#include "rtv_1.h"

t_computations	prepare_computations(t_intersection inter, t_ray r)
{
	t_computations comps;

	comps.t = inter.t;
	comps.object = (t_sphere)(inter.object);
	comps.point = position(r, comps.t);
	comps.eyev = vec4_multiply_1(r.direction, -1);
	comps.normalv = normal_at(&comps.object, comps.point);	
	if (vec4_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.eyev = vec4_multiply_1(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	comps.over_point = vec4_add(comps.point,vec4_multiply_1(comps.normalv, EPSILON));

	return (comps);
}

int	is_shadowed(t_world *world, t_vec4 pnt, int i)
{
	t_vec4 v;
	t_vec4 direction;
	double distance;
	t_ray r;
	t_intersection *xs;
	t_intersection *h;

	v = vec4_substract(world->lights[i].position, pnt); 
	distance = vec4_magnitude(v);
	direction = vec4_normalize(v); 
	r = new_ray(pnt, direction);
	xs = intersect_world(world, r);
	if ((h = hit(xs)) && h->t < distance)
	{
		if (xs)
			free(xs);
		return (1);
	}
	if (xs)
		free(xs);
	return (0);
}

t_color		shade_hit(t_world *w, t_computations comps)
{
	t_color col;
	t_color temp;
	int i;
	int shadow;

	i = 0;
	col = new_color(0);
	while (i < w->lightamount)
	{
		shadow = is_shadowed(w, comps.over_point, i);
		temp = lighting(comps.object.material,
			w->lights[i], comps.point, comps.eyev, 
			comps.normalv, shadow);
		col = color_add(col, temp);
		i++;
	}
	return (col);
}

t_color		color_at(t_world *w, t_ray r)
{
	t_intersection *xs;
	t_intersection *h;
	t_color col;
	t_computations comps;

	xs = intersect_world(w, r);
	if (!(h = hit(xs)))
	{
		if (xs)
			free(xs);
		return (new_color(0));
	}
	comps = prepare_computations(*h, r);
	if (xs)
		free(xs);
	return (shade_hit(w, comps));	
}
