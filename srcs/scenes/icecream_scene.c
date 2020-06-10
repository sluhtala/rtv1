/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   icecream_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:12:07 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 16:59:56 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static void	create_spheres(t_world *world)
{
	double y;
	double x;

	y = 0;
	x = -0.2;
	world->shapes[1] = new_sphere(2);
	world->shapes[1].material.color = new_color(RED);
	set_transform(&world->shapes[1], translate(-0.2 + x, 0 + y, 0.2));
	set_transform(&world->shapes[1], scale(0.5, 0.5, 0.5));
	world->shapes[2] = new_sphere(3);
	world->shapes[2].material.color = new_color(WHITE);
	world->shapes[2].material.diffuse = 1;
	set_transform(&world->shapes[2], translate(0.4 + x, 0 + y, 0.3));
	set_transform(&world->shapes[2], scale(0.5, 0.5, 0.5));
	world->shapes[3] = new_sphere(4);
	world->shapes[3].material.color = new_color(GREEN);
	world->shapes[3].material.diffuse = 1;
	set_transform(&world->shapes[3], translate(0.2 + x, 0 + y, 0.8));
	set_transform(&world->shapes[3], scale(0.7, 0.7, 0.7));
}

void		icecream_scene(t_world *world, t_camera *cam, t_data *data)
{
	*world = new_world(4, 2);
	*cam = new_camera(data->width, data->height, M_PI / 3);
	cam->transform = view_transform(point(0, 2, -6), point(0, 0, 0),
		vector(0, 1, 0));
	world->lights[1].position = point(5, -3, -2);
	world->shapes[0] = new_cone(1);
	world->shapes[0].material.color = new_color(0x5c3508);
	world->shapes[0].material.specular = 0;
	world->shapes[0].maximum = 1.1;
	world->shapes[0].minimum = 0;
	set_transform(&world->shapes[0], translate(-0.1, -2.2, 0.4));
	set_transform(&world->shapes[0], scale(0.6, 1.8, 0.6));
	world->shapes[0].closed = 0;
	create_spheres(world);
}
