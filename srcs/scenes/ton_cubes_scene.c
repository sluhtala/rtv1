/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ton_cubes_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:12:07 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 16:59:56 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

void		ton_cubes_scene(t_world *world, t_camera *cam, t_data *data)
{
	int		i;
	t_vec4	f;

	i = 0;
	*world = new_world(1000, 1);
	*cam = new_camera(data->width, data->height, M_PI / 2);
	world->lights[0].position = point(-10, 20, -5);
	cam->transform = view_transform(point(-15, 7, -4), point(-2, 0, 0),
		vector(0, 1, 0));
	while (i < 1000)
	{
		f.x = i % 10;
		f.y = (int)(i % 100 / 10);
		f.z = (int)(i / 100);
		world->shapes[i] = new_cube(i);
		set_transform(&world->shapes[i], translate(f.x - 5, f.y - 5, f.z));
		set_transform(&world->shapes[i], scale(0.3, 0.3, 0.3));
		i++;
	}
}
