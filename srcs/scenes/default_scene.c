/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:49:29 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:50:03 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

void	default_scene(t_world *world, t_camera *cam, t_data *data)
{
	t_world		dw;
	t_camera	dc;

	dw = default_world();
	dc = new_camera(data->width, data->height, M_PI / 2);
	dc.transform = view_transform(point(0, 4, -5), point(0, 2, 0),
		vector(0, 1, .3));
	*world = dw;
	*cam = dc;
}
