/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_part2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:21:55 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 14:27:26 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static int		check_cap(t_ray *r, double t, double rad)
{
	double x;
	double z;

	x = r->origin.x + t * r->direction.x;
	z = r->origin.z + t * r->direction.z;
	return ((x * x + z * z) <= rad);
}

void			intersect_cone_caps(t_xs *xs, t_cone *c, t_ray *r, int i)
{
	double t;

	if (c->closed == 0 || fabs(r->direction.y) < EPSILON)
		return ;
	t = (c->minimum - r->origin.y) / r->direction.y;
	if (check_cap(r, t, fabs(c->minimum)))
	{
		xs->i[i].t = t;
		xs->i[i].object = (t_cylinder*)c;
		xs->i[i].null = 0;
		xs->i[0].count++;
		i++;
	}
	t = (c->maximum - r->origin.y) / r->direction.y;
	if (check_cap(r, t, fabs(c->maximum)))
	{
		xs->i[i].t = t;
		xs->i[i].object = (t_cylinder*)c;
		xs->i[i].null = 0;
		xs->i[0].count++;
		i++;
	}
}
