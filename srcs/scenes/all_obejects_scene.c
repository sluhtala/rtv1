/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_obejects_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:50:29 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:52:55 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static void	create_cylinder_cone(t_world *world, double dist, double dd)
{
	world->shapes[4] = new_cylinder(3);
	world->shapes[4].maximum = 1;
	world->shapes[4].minimum = -1;
	world->shapes[4].material.color = new_color(GREEN);
	set_transform(&world->shapes[4], translate(dist, 0, 0));
	dist += dd;
	world->shapes[5] = new_cone(5);
	world->shapes[5].maximum = 0;
	world->shapes[5].minimum = -2;
	world->shapes[5].material.color = new_color(0xffff00);
	set_transform(&world->shapes[5], translate(dist, 1, 0));
	set_transform(&world->shapes[5], scale(0.7, 1, 0.7));
}

static void	create_sphere_cube(t_world *world, double dist, double dd)
{
	world->shapes[2].material.color = new_color(RED);
	set_transform(&world->shapes[2], translate(dist, 0, 0));
	dist += dd;
	world->shapes[3] = new_cube(3);
	world->shapes[3].material.color = new_color(BLUE);
	set_transform(&world->shapes[3], translate(dist, 0, 0));
	set_transform(&world->shapes[3], rotate_y(M_PI / 4));
}

static void	create_planes(t_world *world)
{
	t_color bg_color;

	world->shapes[0] = new_plane(0);
	world->shapes[1] = new_plane(1);
	bg_color = new_color(0x888888);
	world->shapes[0].material.color = bg_color;
	world->shapes[1].material.color = new_color(WHITE);
	world->shapes[0].material.specular = 0;
	world->shapes[1].material.specular = 0;
	set_transform(&world->shapes[0], translate(0, -2, 0));
	set_transform(&world->shapes[1], translate(0, 0, 7));
	set_transform(&world->shapes[1], rotate_x(M_PI / 2));
}

void		all_objects_scene(t_world *world, t_camera *cam, t_data *data)
{
	double dist;
	double dd;

	dd = 3.2;
	dist = -4.8;
	*world = new_world(6, 2);
	world->lights[1] = point_light(point(5, 10, -5), new_color(GRAY));
	*cam = new_camera(data->width, data->height, M_PI / 2);
	cam->transform = view_transform(point(-3, 2.2, -5),
		point(-1.5, 0, 0), vector(0, 1, 0));
	cam->inverse = cam->transform.inverse(&cam->transform);
	create_planes(world);
	create_sphere_cube(world, dist, dd);
	dist += dd;
	dist += dd;
	create_cylinder_cone(world, dist, dd);
}
