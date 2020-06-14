/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:37:07 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 16:21:39 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"
#include <stdio.h>

void		error_manager(char *str)
{
	perror(str);
	exit(0);
}

void		close_program(t_data *data)
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

static void	rtv_1(t_data *data, int scene)
{
	t_camera	cam;
	t_world		world;

	if (scene > 4 || scene < 0)
		scene = 0;
	select_scene(&world, &cam, data, scene);
	data->img.pixels = render(cam, &world);
	data->world = world;
}

int			main(int argc, char **argv)
{
	t_data		data;

	data.width = WIDTH;
	data.height = HEIGHT;
	set_options(&data, argc, argv);
	init_rt(&data);
	if (argc == 1)
		rtv_1(&data, 0);
	else
		rtv_1(&data, ft_atoi(argv[1]));
	update_buffer(&data);
	image_to_window(&data);
	if (data.opt.simple == 0)
	{
		mlx_hook(data.mlx.win, 2, 0, (void*)input_manager, &data);
		mlx_hook(data.mlx.win, 17, 0, (void*)close_program, &data);
		mlx_loop(data.mlx.ptr);
	}
	return (0);
}
