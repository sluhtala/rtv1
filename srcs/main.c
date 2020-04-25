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
			img.buf[x * 4 + y * WIDTH * 4 + 0] = (double)img.pixels[y][x].a * 255.0;
			img.buf[x * 4 + y * WIDTH * 4 + 1] = (double)img.pixels[y][x].r * 255.0;
			img.buf[x * 4 + y * WIDTH * 4 + 2] = (double)img.pixels[y][x].b * 255.0;
			img.buf[x * 4 + y * WIDTH * 4 + 3] = (double)img.pixels[y][x].g * 255.0;
			if (img.endian == 0)
			{
				img.buf[x * 4 + y * WIDTH * 4 + 0] = (double)img.pixels[y][x].b * 255.0;
				img.buf[x * 4 + y * WIDTH * 4 + 1] = (double)img.pixels[y][x].g * 255.0;
				img.buf[x * 4 + y * WIDTH * 4 + 2] = (double)img.pixels[y][x].r * 255.0;
				img.buf[x * 4 + y * WIDTH * 4 + 3] = (double)img.pixels[y][x].a * 255.0;
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

t_color		get_color(double world_y, double world_x, t_sphere s, t_light light)
{
	t_color color;
	t_ray	r;
	t_vec4 r_origin;
	t_vec4 pos;
	t_intersection *xs;
	t_intersection hitt;
	t_vec4 point;
	t_vec4 normal;
	t_vec4 eye;

	pos = new_vec4(world_x, world_y, 10.0, 1);
	r_origin = new_vec4(0.0, 0.0, -6.0, 1.0);
	color = new_color(0);
	r.origin = r_origin;
	r.direction = vec4_normalize(vec4_substract(pos, r_origin));
	xs = intersect(s, r);	
	hitt = hit(xs);
	if (hitt.t != -1000)
	{
		point = position(r, hitt.t);
		normal = normal_at(hitt.object, point);
		eye = vec4_multiply_1(r.direction, -1);	
		color = lighting(hitt.object.material, light, point, eye, normal);
	}
	free(xs);
	return (color);
}

int	 sphere_test(t_data *data)
{
	int x;
	int y;
	double world_y;
	double world_x;
	double half;
	double pixel_s;
	t_sphere sphere;
	t_vec4 light_pos;
	t_light light;

	sphere = new_sphere(1);
	sphere.material.color.r = 0;
	sphere.material.color.g = 1;
	sphere.material.color.b = 0;
	light = point_light(new_vec4(-10, 10, -10, 1), new_color(WHITE));

	pixel_s = 7.0 / WIDTH;
	half = 7.0 / 2.0;
	y = 0;
	//sphere.transform = set_transform(sphere, translate(0.5,0.5,0.5));
	sphere.transform = set_transform(sphere, rotate_z(M_PI * 35.0/180.0));
	sphere.transform = set_transform(sphere, scale(1,0.5,1));
	put4x4matrix(sphere.transform.m);
	printf("");
	while (y < HEIGHT)
	{
		x = 0;
		world_y = half - pixel_s * y;
		while (x < WIDTH)
		{
			world_x = -half + pixel_s * x;
			data->img.pixels[y][x] = get_color(world_y, world_x, sphere, light);			
			x++;
		}
		y++;
	}
	return (1);
}

void	my_test()
{
	return ;

}

int		main(int argc, char **argv)
{
	t_data		data;

	if (argc > 2)
		exit(0);
	set_options(&data, argc, argv);
	init_rt(&data);
	sphere_test(&data);	
	my_test();
	update_buffer(data.img);
	image_to_window(&data);
	if (data.opt.simple == 0)
	{
		mlx_hook(data.mlx.win, 2, 0, (void*)input_manager, &data);
		mlx_hook(data.mlx.win, 17, 0, (void*)close_program, &data);
		mlx_loop(data.mlx.ptr);
	}
//	ft_printf("");
	exit(0);
	return (0);
}
