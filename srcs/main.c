#include "rtv_1.h"

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

void	init_pixels(t_color **pix, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			pix[j][i].r = 0;
			pix[j][i].g = 0;
			pix[j][i].b = 0;
			pix[j][i].a = 0;
			i++;
		}
		j++;
	}
}

void	init_rt(t_data *data)
{
	int i;

	i = 0;
	data->img.pixels = NULL;
	data->img.buf = NULL;
	data->mlx.ptr = mlx_init();
	if (data->opt.simple == 0)
		data->mlx.win = mlx_new_window(data->mlx.ptr, WIDTH, HEIGHT, TITLE);
	data->img.ptr = mlx_new_image(data->mlx.ptr, WIDTH, HEIGHT);
	data->img.buf = mlx_get_data_addr(data->img.ptr, &data->img.bit_pix, &data->img.size_line, &data->img.endian);
	if (!(data->img.pixels = (t_color**)malloc(sizeof(t_color*) * HEIGHT)))
		error_manager("MALLOC error");
	while (i < HEIGHT)
	{
		if (!(data->img.pixels[i] = (t_color*)malloc(sizeof(t_color) * WIDTH)))
			error_manager("MALLOC error");
		i++;
	}
	init_pixels(data->img.pixels, WIDTH, HEIGHT);
}


void	image_to_window(t_data *data)
{
	if (data->opt.simple == 0)
	{
		mlx_clear_window(data->mlx.ptr, data->mlx.win);
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
	}
}

void	update_buffer(t_image img)
{
	int x;
	int y;
	
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			img.buf[x * 4 + y * WIDTH * 4 + 0] = img.pixels[y][x].a;
			img.buf[x * 4 + y * WIDTH * 4 + 1] = img.pixels[y][x].r;
			img.buf[x * 4 + y * WIDTH * 4 + 2] = img.pixels[y][x].b;
			img.buf[x * 4 + y * WIDTH * 4 + 3] = img.pixels[y][x].g;
			if (img.endian == 0)
			{
				img.buf[x * 4 + y * WIDTH * 4 + 0] = img.pixels[y][x].b;
				img.buf[x * 4 + y * WIDTH * 4 + 1] = img.pixels[y][x].g;
				img.buf[x * 4 + y * WIDTH * 4 + 2] = img.pixels[y][x].r;
				img.buf[x * 4 + y * WIDTH * 4 + 3] = img.pixels[y][x].a;
			}
			x++;
		}
		y++;
	}
}


/*
**	
**
**
*/

void	set_options(t_data *data, int ac, char **av)
{
	data->opt.simple = 0;
	if (ac == 1)
	{
		return ;
	}
	if (ft_strcmp(av[1], "-s") == 0)
	{
		data->opt.simple = 1;
	}
}

t_color		get_color(double world_y, double world_x, t_sphere s)
{
	t_color color;
	t_ray	r;
	t_vec4 r_origin;
	t_vec4 position;
	t_intersection *xs;

	position = new_vec4(world_x, world_y, 10.0, 1.0);
	r_origin = new_vec4(0.0, 0.0, -5.0, 1.0);
	color = new_color(0);
	r.origin = r_origin;
	r.direction = vec4_normalize(vec4_substract(position, r_origin));
	xs = intersect(s, r);
	if (hit(xs).t != -1000)
	{
		color = new_color(0xff0000);
	}
	free(xs);
	return (color);
}

void	sphere_test(t_data *data)
{
	int x;
	int y;
	double world_y;
	double world_x;
	double half;
	double pixel_s;
	t_sphere sphere;

	sphere = new_sphere(1);
	pixel_s = 7.0 / WIDTH;
	half = 7.0 / 2.0;
	y = 0;
	world_x = 0.0;
	world_y = 0.0;

	while (y < HEIGHT)
	{
		x = 0;
		world_y = half - pixel_s * y;
		while (x < WIDTH)
		{
			world_x = -half + pixel_s * x;
			data->img.pixels[y][x] = get_color(world_y, world_x, sphere);			
			//data->img.pixels[y][x] = new_color(0xff0000);
			x++;
		}
		y++;
	}
}

int		main(int argc, char **argv)
{
	t_data		data;

	if (argc > 2)
		exit(0);
	set_options(&data, argc, argv);
	init_rt(&data);
	sphere_test(&data);	
	update_buffer(data.img);
	image_to_window(&data);
	if (data.opt.simple == 0)
	{
		mlx_hook(data.mlx.win, 2, 0, (void*)input_manager, &data);
		mlx_hook(data.mlx.win, 17, 0, (void*)close_program, &data);
		mlx_loop(data.mlx.ptr);
	}
	exit(0);
	return (0);
}
