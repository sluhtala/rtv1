#include "rtv_1.h"

void	default_scene(t_world *world, t_camera *cam, t_data *data)
{
	t_world dw;
	t_camera dc;

	dw = default_world();
	dc = new_camera(data->width, data->height, M_PI / 2);
	dc.transform = view_transform(point(0,4,-5), point(0,2,0), vector(0,1,.3));
	*world = dw;
	*cam = dc;
}

void	all_scene(t_world *world, t_camera *cam, t_data *data)
{
	t_color bg_color;
	double dist;
	double dd = 3.2;

	*world = new_world(6, 2);
	world->lights[1] = point_light(point(5,10,-5), new_color(GRAY));
	*cam = new_camera(data->width, data->height, M_PI / 2);
	cam->transform = view_transform(point(-3, 2.2, -5), point(-1.5,0,0),vector(0,1,0));
	//set background planes
	world->shapes[0] = new_plane(0);
	world->shapes[1] = new_plane(1);
	bg_color = new_color(0x888888);
	world->shapes[0].material.color = bg_color;
	world->shapes[1].material.color = new_color(WHITE);
	world->shapes[0].material.specular = 0;	
	world->shapes[1].material.specular = 0;	
	set_transform(&world->shapes[0], translate(0, -2, 0));
	set_transform(&world->shapes[1], translate(0, 0, 7));
	set_transform(&world->shapes[1], rotate_x(M_PI / 2));
	//sphere
	dist = -4.8;
	world->shapes[2].material.color = new_color(RED);
	set_transform(&world->shapes[2], translate(dist, 0, 0));
	dist += dd;
	//cube
	world->shapes[3] = new_cube(3);
	world->shapes[3].material.color = new_color(BLUE);
	set_transform(&world->shapes[3], translate(dist, 0, 0));
	set_transform(&world->shapes[3], rotate_y(M_PI/4));
	dist += dd;
	//cylinder	
	world->shapes[4] = new_cylinder(3);
	world->shapes[4].maximum = 1;
	world->shapes[4].minimum = -1;
	world->shapes[4].material.color = new_color(GREEN);
	set_transform(&world->shapes[4], translate(dist, 0, 0));
	dist += dd;
	//cone
	world->shapes[5] = new_cone(5);
	world->shapes[5].maximum = 0;
	world->shapes[5].minimum = -2;
	world->shapes[5].material.color = new_color(0xffff00);
	set_transform(&world->shapes[5], translate(dist, 1, 0));
	set_transform(&world->shapes[5], scale(0.7, 1, 0.7));
}
