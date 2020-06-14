/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:09:53 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:11:37 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	data->img.buf = NULL;
	if (!(data->mlx.ptr = mlx_init()))
		error_manager("Mlx error");
	if (data->opt.simple == 0)
		data->mlx.win = mlx_new_window(data->mlx.ptr,
			data->width, data->height, TITLE);
	if (!data->mlx.win)
		error_manager("Mlx error");
	data->img.ptr = mlx_new_image(data->mlx.ptr, data->width, data->height);
	if (!data->img.ptr)
		error_manager("Mlx error");
	data->img.buf = mlx_get_data_addr(data->img.ptr,
		&data->img.bit_pix, &data->img.size_line, &data->img.endian);
	if (!data->img.buf)
		error_manager("Mlx error");
}

void	image_to_window(t_data *data)
{
	if (data->opt.simple == 0)
	{
		mlx_clear_window(data->mlx.ptr, data->mlx.win);
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
		data->img.ptr, 0, 0);
	}
}

void	update_buffer(t_data *data)
{
	int			ixy[3];
	t_icolor	color;

	ixy[0] = 0;
	while (ixy[0] < data->height * data->width * 4)
	{
		ixy[2] = (ixy[0] / 4) / data->width;
		ixy[1] = (ixy[0] / 4) - ixy[2] * data->width;
		color = color_to_uint8(data->img.pixels[ixy[2]][ixy[1]]);
		if (data->img.endian == 1)
		{
			data->img.buf[ixy[0]] = (char)color.a;
			data->img.buf[ixy[0] + 1] = (char)color.r;
			data->img.buf[ixy[0] + 2] = (char)color.g;
			data->img.buf[ixy[0] + 3] = (char)color.b;
		}
		else
		{
			data->img.buf[ixy[0]] = (char)color.b;
			data->img.buf[ixy[0] + 1] = (char)color.g;
			data->img.buf[ixy[0] + 2] = (char)color.r;
			data->img.buf[ixy[0] + 3] = (char)color.a;
		}
		ixy[0] += 4;
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
	if (ac == 3 || ac == 4)
	{
		if ((data->width = ft_atoi(av[2])) <= 0)
			data->width = WIDTH;
		if (ac == 4)
			if ((data->height = ft_atoi(av[3])) <= 0)
				data->height = HEIGHT;
		if (ac == 3)
			data->height = data->width * 0.7;
	}
}
