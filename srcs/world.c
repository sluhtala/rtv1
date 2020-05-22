#include "rtv_1.h"

t_world 	*world()
{
	t_world *w;

	w = (t_world*)malloc(sizeof(t_world));
	return (w);
}

t_world		*default_world()
{
	t_world *world;
	t_light light;
	world = malloc(sizeof(t_world));
	light = point_light(point(-10,10,10), new_color(0xffffff));
	t_sphere *s1 = new_sphere(1);
	t_sphere *s2 = new_sphere(2);
	world->spheres = malloc(sizeof(t_sphere*) * 2);
	world->amount = 2;
	s1->material->color = new_color(0xaaff99);
	s1->material->diffuse = 0.7;
	s1->material->specular = 0.2;
	set_transform(s2,scale(0.5, 0.5, 0.5));
	world->spheres[0] = s1;
	world->spheres[1] = s2;
	world->light = light;
	return (world);
}
/*
#include <stdio.h>
int main()
{
	t_world *w = default_world();
	t_ray r = new_ray(point(0,0,-5), vector(0,0,1));
	t_intersection *xs = intersect_world(w, r);
	printf("%f\n%f\n%f\n%f\n", xs[0].t, xs[1].t, xs[2].t,xs[3].t);
	return (0);
}
*/
