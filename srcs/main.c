#include "rtv_1.h"
#include <stdio.h>

void	error_manager(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	close_program(t_data *data)
{
	int i;

	if (data->opt.simple == 0)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->img.pixels != NULL)
	{
		i = 0;
		while (i < data->height)
		{
			free(data->img.pixels[i]);
			i++;
		}
		free(data->img.pixels);
		data->img.pixels = NULL;
	}
	exit(0);
}


void test(t_data* data)
{
	t_world w = default_world();
	t_ray r = new_ray(point(0,0,-5), vector(0,0,1));
	t_intersection *xs = intersect_world(&w, r);
	int i = 0;
	while (i < xs[0].count)
	{
		printf("%f\n", xs[i].t);
		i++;
	}
	close_program(data);	
}

void viewtest()
{
	t_vec4 from = point(1, 3, 2);
	t_vec4 to = point(4, -2, 8);
	t_vec4 up = vector(1, 1, 0);
	t_matrix m = view_transform(from, to, up);
	put4x4matrix(m);
	exit(0);
}

void test_render(t_data *data)
{
	t_world world;

	data->camera = new_camera(data->width, data->height, M_PI *90/ 180);
	data->camera.transform = view_transform(point(0,1,-6),
	 point(0,0,0), vector(0,1,0));
	world.spheres = malloc(sizeof(t_sphere) * 6);
	world.objectamount = 6;
	world.lightamount = 1;
	world.lights = malloc(sizeof(t_light));
	world.lights[0] = point_light(point(-10,10,-10), new_color(0xffffff));
	world.spheres[0] = new_sphere(1);

	set_transform(&world.spheres[0], translate(0,-1,0));
	set_transform(&world.spheres[0], scale(20, 0.01,20));
	world.spheres[0].material.color = new_color(WHITE);
	world.spheres[1] = new_sphere(2);
	set_transform(&world.spheres[1], translate(8,0,0));
	set_transform(&world.spheres[1], rotate_y(-M_PI/4));
	set_transform(&world.spheres[1], scale(0.01,20,20));
	world.spheres[1].material.color = new_color(WHITE);
	
	world.spheres[2] = new_sphere(3);
	set_transform(&world.spheres[2], translate(-8,0,0));
	set_transform(&world.spheres[2], rotate_y(M_PI/4));
	set_transform(&world.spheres[2], scale(0.01,20,20));
	world.spheres[2].material.color = new_color(WHITE);
	
	world.spheres[3] = new_sphere(4);
	world.spheres[4] = new_sphere(5);
	world.spheres[5] = new_sphere(6);

	set_transform(&world.spheres[4], translate(-3,0,2));
	set_transform(&world.spheres[4], scale(.4,.4,.4));
	
	set_transform(&world.spheres[5], translate(2,2,-2));
	set_transform(&world.spheres[5], scale(.4,.4,.4));
	world.spheres[3].material.color = new_color(RED);
	world.spheres[4].material.color = new_color(GREEN);
	world.spheres[5].material.color = new_color(BLUE);
	data->img.pixels = render(data->camera, &world); 
	data->world = world;
}

void shadow_test(t_data *data)
{
	t_world world = default_world();
	t_camera cam = new_camera(data->width, data->height, M_PI/2);
	world.lights[0].position = point(-3,3,0);
	cam.transform = view_transform( point(0,1,-4), point(0,0,0), vector(0,1,0));	
	data->img.pixels = render(cam, &world);
	data->world = world;
}

int		main(int argc, char **argv)
{
	t_data		data;

	if (argc > 2)
		exit(0);
	set_options(&data, argc, argv);
	data.opt.auto_image = 0;
	data.width = 600;
	data.height = 600;

	test_render(&data);
	//shadow_test(&data);
	init_rt(&data);
	update_buffer(data.img, &data);
	image_to_window(&data);
	if(data.opt.auto_image == 1)
		img_to_ppm(data.img, "images/image_auto.ppm", &data);
	if (data.opt.simple == 0)
	{
		mlx_hook(data.mlx.win, 2, 0, (void*)input_manager, &data);
		mlx_hook(data.mlx.win, 17, 0, (void*)close_program, &data);
		mlx_loop(data.mlx.ptr);
	}
	return (0);
}
