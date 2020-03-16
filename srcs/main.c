#include "rtv_1.h"

void	error_manager(char *str)
{
	ft_putendl(str);
	exit(0);
}

void	close_program(t_data *data)
{
	int i;

	mlx_destroy_window(data->mlx.ptr, data->mlx.win);
	if (data->img.pixels != NULL)
	{
		i = 0;
		while (i < HEIGHT && data->img.pixels[i] != NULL)
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
	data->mlx.ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.ptr, WIDTH, HEIGHT, TITLE);
	data->img.ptr = mlx_new_image(data->mlx.ptr, WIDTH, HEIGHT);
	data->img.buf = mlx_get_data_addr(data->img.ptr, &data->img.bit_pix, &data->img.size_line, &data->img.endian);
	if (!(data->img.pixels = (t_color**)malloc(sizeof(t_color*) * HEIGHT)))
		error_manager("MALLOC error");
	while (i < WIDTH)
	{
		if (!(data->img.pixels[i] = (t_color*)malloc(sizeof(t_color) * WIDTH)))
			error_manager("MALLOC error");
		i++;
	}
	init_pixels(data->img.pixels, WIDTH, HEIGHT);
}


void	image_to_window(t_data *data)
{
	mlx_clear_window(data->mlx.ptr, data->mlx.win);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win, data->img.ptr, 0, 0);
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

t_triangle	create_triangle(t_vec3 a, t_vec3 b, t_vec3 c, int hex)
{
	t_color col;
	t_triangle tri;

	col.r = hex >> 16;
	col.g = hex >> 8 & 0xff;
	col.b = hex & 0xff;
	tri.a = a;
	tri.b = b;
	tri.c = c;
	tri.col = col;
	return(tri);
}
	
int		main()
{
	t_data		data;
	t_triangle	tri;

	init_rt(&data);
	tri = create_triangle(a, b, c, BLUE);	

	update_buffer(data.img);
	image_to_window(&data);
	mlx_hook(data.mlx.win, 2, 0, (void*)input_manager, &data);
	mlx_hook(data.mlx.win, 17, 0, (void*)close_program, &data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
