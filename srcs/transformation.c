/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:03:25 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:05:34 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

t_matrix		translate(double x, double y, double z)
{
	t_matrix	m;

	m = new_matrix();
	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = x;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = y;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = z;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix		scale(double x, double y, double z)
{
	t_matrix	m;

	m = new_matrix();
	m.m[0][0] = x;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = y;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = z;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix		rotate_x(double r)
{
	t_matrix	m;

	m = new_matrix();
	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = cos(r);
	m.m[1][2] = -sin(r);
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = sin(r);
	m.m[2][2] = cos(r);
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix		rotate_y(double r)
{
	t_matrix	m;

	m = new_matrix();
	m.m[0][0] = cos(r);
	m.m[0][1] = 0;
	m.m[0][2] = sin(r);
	m.m[0][3] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = -sin(r);
	m.m[2][1] = 0;
	m.m[2][2] = cos(r);
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix		rotate_z(double r)
{
	t_matrix	m;

	m = new_matrix();
	m.m[0][0] = cos(r);
	m.m[0][1] = -sin(r);
	m.m[0][2] = 0;
	m.m[0][3] = 0;
	m.m[1][0] = sin(r);
	m.m[1][1] = cos(r);
	m.m[1][2] = 0;
	m.m[1][3] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}
