/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:51:23 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 14:52:16 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

t_vec4	vec4_cros(t_vec4 v1, t_vec4 v2)
{
	t_vec4 c;

	c.x = v1.y * v2.z - v1.z * v2.y;
	c.y = v1.z * v2.x - v1.x * v2.z;
	c.z = v1.x * v2.y - v1.y * v2.x;
	return (c);
}

double	vec4_dot(t_vec4 v1, t_vec4 v2)
{
	double dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	return (dot);
}

double	vec4_magnitude(t_vec4 v)
{
	double m;

	m = sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	return (m);
}

t_vec4	vec4_normalize(t_vec4 v)
{
	double m;

	m = vec4_magnitude(v);
	if (m == 0)
		return (v);
	v.x /= m;
	v.y /= m;
	v.z /= m;
	v.w /= m;
	return (v);
}
