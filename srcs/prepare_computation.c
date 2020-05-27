#include "rtv_1.h"

t_computations	prepare_computations(t_intersection inter, t_ray r)
{
	t_computations comps;

	comps.t = inter.t;
	comps.object = inter.object;
	comps.point = position(r, comps.t);
	comps.eyev = vec4_multiply_1(r.direction, -1);
	comps.normalv = normal_at(comps.object, comps.point);	
	if (vec4_dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = 1;
		comps.eyev = vec4_multiply_1(comps.normalv, -1);
	}
	else
		comps.inside = 0;
	return (comps);
}

t_color		shade_hit(t_world *w, t_computations comps)
{
	t_color col;
	t_color temp;
	int i;

	i = 0;
	col = new_color(0);
	while (i < w->lightamount)
	{
		temp = lighting(*comps.object->material,
			w->lights[i], comps.point, comps.eyev, 
			comps.normalv);
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
		return (new_color(0));
	comps = prepare_computations(*h, r);
	if (xs)
		free(xs);
	return (shade_hit(w, comps));	
}
