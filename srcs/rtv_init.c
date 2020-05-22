#include "rtv_1.h"

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
			img.buf[x * 4 + y * WIDTH * 4 + 0] = (img.pixels[y][x].a * 255.0);
			img.buf[x * 4 + y * WIDTH * 4 + 1] = (img.pixels[y][x].r * 255.0);
			img.buf[x * 4 + y * WIDTH * 4 + 2] = (img.pixels[y][x].g * 255.0);
			img.buf[x * 4 + y * WIDTH * 4 + 3] = (img.pixels[y][x].b * 255.0);
			if (img.endian == 0)
			{
				img.buf[x * 4 + y * WIDTH * 4 + 0] = (img.pixels[y][x].b * 255.0);
				img.buf[x * 4 + y * WIDTH * 4 + 1] = (img.pixels[y][x].g * 255.0);
				img.buf[x * 4 + y * WIDTH * 4 + 2] = (img.pixels[y][x].r * 255.0);
				img.buf[x * 4 + y * WIDTH * 4 + 3] = (img.pixels[y][x].a * 255.0);
			}
			x++;
		}
		y++;
	}
}

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
