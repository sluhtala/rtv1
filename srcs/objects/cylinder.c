/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:13:52 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 14:47:07 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static t_vec4	get_discriminant(t_ray r, t_xs *xs)
{
	t_vec4 d;

	*xs = xs_init();
	d.x = (r.direction.x * r.direction.x + r.direction.z * r.direction.z);
	d.y = 2 * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	d.z = r.origin.x * r.origin.x + r.origin.z * r.origin.z - 1;
	d.w = d.y * d.y - 4 * d.x * d.z;
	return (d);
}

t_xs			intersect_cylinder(t_cylinder *c, t_ray r)
{
	t_xs	xs;
	double	t[2];
	t_vec4	d;
	double	y[2];
	int		i;

	if ((d = get_discriminant(r, &xs)).w < 0)
		return (xs);
	t[0] = (-d.y - sqrt(d.w)) / (2 * d.x);
	t[1] = (-d.y + sqrt(d.w)) / (2 * d.x);
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
	intersect_cylinder_caps(&xs, c, &r, i);
	return (xs);
}

t_vec4			cylinder_normal_at(t_shape *shape, t_vec4 point)
{
	double dist;

	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= shape->maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && point.y <= shape->minimum + EPSILON)
		return (vector(0, 1, 0));
	return (vector(point.x, 0, point.z));
}

t_cylinder		new_cylinder(int id)
{
	t_cylinder c;

	c.type = CYLINDER;
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
