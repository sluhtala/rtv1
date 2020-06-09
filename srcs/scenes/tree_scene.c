/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:12:07 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 16:59:56 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static void	create_tree(t_world *world)
{
	t_material leaf_material;

	world->shapes[2] = new_cylinder(3);
	world->shapes[2].maximum = 5;
	world->shapes[2].minimum = -4;
	world->shapes[2].material.color = new_color(0x5c3508);
	world->shapes[4] = new_cylinder(3);
	world->shapes[4].maximum = 3;
	world->shapes[4].minimum = -7;
	world->shapes[4].material.color = new_color(0x5c3508);
	set_transform(&world->shapes[4], translate(-1, 1.5, 0));
	set_transform(&world->shapes[4], rotate_z(M_PI / 3.5));
	set_transform(&world->shapes[4], scale(0.2, .2, .2));
	leaf_material = new_material();
	leaf_material.color = new_color(0x05ff05);
	leaf_material.specular = 0;
	world->shapes[3] = new_sphere(4);
	world->shapes[3].material = leaf_material;
	set_transform(&world->shapes[3], translate(0, 5, 0));
	set_transform(&world->shapes[3], scale(3, 3, 3));
	world->shapes[5] = new_sphere(4);
	world->shapes[5].material = leaf_material;
	set_transform(&world->shapes[5], translate(-1.6, 2, 0));
	set_transform(&world->shapes[5], scale(.6, .6, .6));
}

void		tree_scene(t_world *world, t_camera *cam, t_data *data)
{
	*world = new_world(6, 2);
	*cam = new_camera(data->width, data->height, M_PI / 2);
	world->lights[1] = point_light(point(10, 10, 0), new_color(0x6666ff));
	cam->transform = view_transform(point(0, 0, -10), point(0, 3, 0),
		vector(0, 1, 0));
	world->shapes[1] = new_sphere(2);
	world->shapes[1].material.color = new_color(GREEN);
	set_transform(&world->shapes[1], translate(0, -2, 0));
	set_transform(&world->shapes[1], scale(10, 1, 10));
	world->shapes[0] = new_plane(1);
	world->shapes[0].material.color = new_color(0x03dbfc);
	world->shapes[0].material.specular = 0;
	world->shapes[0].material.diffuse = 1;
	set_transform(&world->shapes[0], translate(0, 0, 100));
	set_transform(&world->shapes[0], rotate_x(M_PI / 2));
	create_tree(world);
}
