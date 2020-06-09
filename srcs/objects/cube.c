/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:48:07 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 13:52:30 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static void	check_axis(double origin, double direction, double *t)
{
	double tmin_numerator;
	double tmax_numerator;
	double temp;

	tmin_numerator = (-1 - origin);
	tmax_numerator = (1 - origin);
	if (fabs(direction) >= EPSILON)
	{
		t[0] = tmin_numerator / direction;
		t[1] = tmax_numerator / direction;
	}
	else
	{
		t[0] = tmin_numerator * INFINITY;
		t[1] = tmax_numerator * INFINITY;
	}
	if (t[0] > t[1])
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
}

t_xs		intersect_cube(t_cube *c, t_ray r)
{
	t_xs	xs;
	double	xt[2];
	double	yt[2];
	double	zt[2];
	double	t[2];

	xs = xs_init();
	check_axis(r.origin.x, r.direction.x, xt);
	check_axis(r.origin.y, r.direction.y, yt);
	check_axis(r.origin.z, r.direction.z, zt);
	t[0] = fmax(xt[0], fmax(yt[0], zt[0]));
	t[1] = fmin(xt[1], fmin(yt[1], zt[1]));
	if (t[0] > t[1])
		return (xs);
	xs.i[0].t = t[0];
	xs.i[0].count = 2;
	xs.i[0].object = (t_shape*)c;
	xs.i[0].null = 0;
	xs.i[1].t = t[1];
	xs.i[1].count = 2;
	xs.i[1].object = (t_shape*)c;
	xs.i[1].null = 0;
	return (xs);
}

t_vec4		cube_normal_at(t_vec4 point)
{
	double maxc;

	maxc = fmax(fabs(point.x), fmax(fabs(point.y), fabs(point.z)));
	if (maxc == fabs(point.x))
	{
		return (vector(point.x, 0, 0));
	}
	else if (maxc == fabs(point.y))
	{
		return (vector(0, point.y, 0));
	}
	return (vector(0, 0, point.z));
}

t_cube		new_cube(int id)
{
	t_cube c;

	c.type = CUBE;
	c.id = id;
	c.transform = new_matrix();
	c.material = new_material();
	c.transform.identity(&c.transform);
	c.inverse = new_matrix();
	return (c);
}
