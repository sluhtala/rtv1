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
		while (i < HEIGHT)
		{
			free(data->img.pixels[i]);
			i++;
		}
		free(data->img.pixels);
		data->img.pixels = NULL;
	}
	exit(0);
}


int		main(int argc, char **argv)
{
	t_data		data;

	if (argc > 2)
		exit(0);
	set_options(&data, argc, argv);
	
	init_rt(&data);
	data.opt.auto_image = 0;
	sphere_test(&data);
	update_buffer(data.img);
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
