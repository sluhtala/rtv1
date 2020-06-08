#include "rtv_1.h"
#include <stdio.h>

void	error_manager(char *str)
{
	perror(str);
	exit(0);
}

void	close_program(t_data *data)
{
	int i;

	if (data->opt.simple == 0)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->world.shapes)
		free(data->world.shapes);
	if (data->world.lights)
		free(data->world.lights);
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

void plane_test(t_data *data)
{
	t_camera cam;
	t_world world;

	all_scene(&world, &cam, data);
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
	data.width = WIDTH;
	data.height = HEIGHT;

	plane_test(&data);
	init_rt(&data);
	update_buffer(&data);
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
