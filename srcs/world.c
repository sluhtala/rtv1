/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:38:34 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:35:07 by sluhtala         ###   ########.fr       */
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
	t_sphere	s1;

	s1 = new_sphere(1);
	world.objectamount = 3;
	world.lightamount = 1;
	world.lights = (t_light*)malloc(sizeof(t_light) * world.lightamount);
	world.lights[0] = point_light(point(-5, 10, -5), new_color(0xffffff));
	world.shapes = (t_shape*)malloc(sizeof(t_shape) * world.objectamount);
	world.shapes[0] = new_plane(3);
	world.shapes[1] = new_plane(4);
	s1.material.color = new_color(GREEN);
	s1.material.diffuse = 0.7;
	s1.material.specular = 0.2;
	world.shapes[0].material.specular = 0;
	world.shapes[1].material.color = new_color(0x000099);
	world.shapes[1].material.specular = 0;
	set_transform(&world.shapes[0], translate(0, -1, 0));
	set_transform(&world.shapes[1], translate(0, 0, 8));
	set_transform(&world.shapes[1], rotate_x(-M_PI / 2));
	world.shapes[2] = s1;
	set_transform(&world.shapes[2], translate(0, 1, 0));
	return (world);
}

void		delete_world(t_world *world)
{
	if (world->shapes)
		free(world->shapes);
	if (world->lights)
		free(world->lights);
}
