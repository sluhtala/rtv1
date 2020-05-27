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
	t_world *w = default_world();
	t_ray r = new_ray(point(0,0,-5), vector(0,0,1));
	t_intersection *xs = intersect_world(w, r);
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
	t_4x4matrix *m = view_transform(from, to, up);
	put4x4matrix(m);
	free(m);	
	exit(0);
}

void test_render(t_data *data)
{
	t_world *world;
	data->camera = new_camera(data->width, data->height, M_PI *60/ 180);
	data->camera.transform = view_transform(point(0,0,-4),
	 point(0,0,0), vector(0,1,0));
	world = default_world();
	data->img.pixels = render(data->camera, world); 
	data->world = world;
}

int		main(int argc, char **argv)
{
	t_data		data;

	if (argc > 2)
		exit(0);
	set_options(&data, argc, argv);
	data.opt.auto_image = 0;
	data.width = 200;
	data.height = 200;

	test_render(&data);
	init_rt(&data);
	update_buffer(data.img, &data);
	image_to_window(&data);
	if(data.opt.auto_image == 1)
		img_to_ppm(data.img, "images/image_auto.ppm");
	if (data.opt.simple == 0)
	{
		mlx_hook(data.mlx.win, 2, 0, (void*)input_manager, &data);
		mlx_hook(data.mlx.win, 17, 0, (void*)close_program, &data);
		mlx_loop(data.mlx.ptr);
	}
	return (0);
}
