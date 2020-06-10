/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:38:34 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 16:13:09 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

t_world		new_world(int object_amount, int light_amount)
{
	t_world	w;
	int		i;

	w.objectamount = object_amount;
	w.lightamount = light_amount;
	w.lights = (t_light*)malloc(sizeof(t_light) * light_amount);
	w.shapes = (t_shape*)malloc(sizeof(t_shape) * object_amount);
	if (!w.lights || !w.shapes)
		error_manager("MALLOC error");
	i = 0;
	while (i < object_amount)
	{
		w.shapes[i] = new_sphere(i);
		i++;
	}
	i = 0;
	while (i < light_amount)
	{
		w.lights[i] = point_light(point(-5, 10, -5), new_color(0xffffff));
		i++;
	}
	return (w);
}

t_world		default_world(void)
{
	t_world		world;

	world = new_world(2, 1);
	world.lights[0] = point_light(point(-10, 10, -10), new_color(0xffffff));
	world.shapes[0] = new_plane(1);
	world.shapes[0].material.specular = 0;
	world.shapes[1] = new_sphere(2);
	set_transform(&world.shapes[0], translate(0, -1, 0));
	set_transform(&world.shapes[1], translate(0, 0, 0));
	return (world);
}

void		delete_world(t_world *world)
{
	if (world->shapes)
		free(world->shapes);
	if (world->lights)
		free(world->lights);
}
