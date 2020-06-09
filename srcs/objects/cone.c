/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:46:25 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 14:42:56 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static t_vec4	get_discriminant(t_xs *xs, t_ray r)
{
	t_vec4 d;

	*xs = xs_init();
	d.x = pow(r.direction.x, 2) - pow(r.direction.y, 2) +
		pow(r.direction.z, 2);
	d.y = 2 * r.origin.x * r.direction.x - 2 * r.origin.y *
		r.direction.y + 2 * r.origin.z * r.direction.z;
	d.z = r.origin.x * r.origin.x - r.origin.y * r.origin.y + r.origin.z
		* r.origin.z;
	d.w = d.y * d.y - 4 * d.x * d.z;
	return (d);
}

static void		get_t(double *t, t_vec4 d)
{
	if (d.x == 0 && d.y != 0)
	{
		t[0] = -d.z / 2 * d.y;
		t[1] = -d.z / 2 * d.y;
	}
	else
	{
		t[0] = (-d.y - sqrt(d.w)) / (2 * d.x);
		t[1] = (-d.y + sqrt(d.w)) / (2 * d.x);
	}
}

t_xs			intersect_cone(t_cone *c, t_ray r)
{
	t_xs	xs;
	double	t[2];
	t_vec4	d;
	double	y[2];
	int		i;

	if ((d = get_discriminant(&xs, r)).w < 0)
		return (xs);
	get_t(t, d);
	y[0] = r.origin.y + t[0] * r.direction.y;
	i = 0;
	if (c->minimum < y[0] && y[0] < c->maximum)
	{
		xs.i[i] = new_intersection(c, t[0], i + 1);
		i++;
	}
	y[1] = r.origin.y + t[1] * r.direction.y;
	if (c->minimum < y[1] && y[1] < c->maximum)
	{
		xs.i[i] = new_intersection(c, t[1], i + 1);
		i++;
	}
	intersect_cone_caps(&xs, c, &r, i);
	return (xs);
}

t_vec4			cone_normal_at(t_shape *shape, t_vec4 point)
{
	double dist;
	double y;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= shape->maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && point.y <= shape->minimum + EPSILON)
		return (vector(0, 1, 0));
	y = sqrt(point.x * point.x + point.z * point.z);
	if (point.y > 0)
		y = -y;
	return (vector(point.x, y, point.z));
}

t_cone			new_cone(int id)
{
	t_cylinder c;

	c.type = CONE;
	c.id = id;
	c.transform = new_matrix();
	c.material = new_material();
	c.transform.identity(&c.transform);
	c.minimum = -INFINITY;
	c.maximum = INFINITY;
	c.closed = 1;
	c.inverse = new_matrix();
	return (c);
}
