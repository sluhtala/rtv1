#include "rtv_1.h"

t_world 	new_world()
{
	t_world w;

	w.objectamount = 0;
	w.lightamount = 0;
	return (w);
}

t_world		default_world()
{
	t_world world;
	
	t_sphere s1 = new_sphere(1);
	t_sphere s2 = new_sphere(2);
	world.objectamount = 3;
	world.lightamount = 1;
	world.lights = (t_light*)malloc(sizeof(t_light) * world.lightamount);
	world.lights[0] =  point_light(point(-10,10,-10), new_color(0xffffff));
	world.spheres = (t_sphere*)malloc(sizeof(t_sphere) * world.objectamount);
	s1.material.color = new_color(GREEN);
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
	s2.material = new_material();
	world.spheres[2] = new_sphere(3);
	set_transform(&world.spheres[2], translate(0,-1,0));
	set_transform(&world.spheres[2], scale(20,0.01,20));
	set_transform(&s2, scale(0.5, 0.5, 0.5));
	world.spheres[0] = s1;
	world.spheres[1] = s2;
	return (world);
}

void	delete_world(t_world *world)
{
	if (world->spheres)
		free(world->spheres);
	if (world->lights)
		free(world->lights);
}
