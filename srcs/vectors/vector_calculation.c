/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:50:47 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 14:50:50 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

t_vec4	vec4_divide(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	if (v2.x == 0 || v2.y == 0 || v2.z == 0 || v2.w == 0)
		return (v2);
	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	result.w = v1.w / v2.w;
	return (result);
}

t_vec4	vec4_multiply_2(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	result.w = v1.w * v2.w;
	return (result);
}

t_vec4	vec4_multiply_1(t_vec4 v1, double d)
{
	t_vec4 result;

	result.x = v1.x * d;
	result.y = v1.y * d;
	result.z = v1.z * d;
	result.w = v1.w * d;
	return (result);
}

t_vec4	vec4_substract(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	result.w = v1.w - v2.w;
	return (result);
}

t_vec4	vec4_add(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	result.w = v1.w + v2.w;
	return (result);
}
