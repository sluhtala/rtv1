/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_determinant.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:00:14 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:01:52 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

double		determinant2x2(t_matrix *m)
{
	double d;

	d = m->m[0][0] * m->m[1][1] - m->m[0][1] * m->m[1][0];
	return (d);
}

double		determinant3x3(t_matrix *m)
{
	int		i;
	double	d;

	i = 0;
	d = 0.0;
	while (i < 3)
	{
		d = d + m->m[0][i] * cofactor3x3(m, 0, i);
		i++;
	}
	return (d);
}

double		determinant4x4(t_matrix *m)
{
	int		i;
	double	d;

	i = 0;
	d = 0.0;
	while (i < 4)
	{
		d = d + m->m[0][i] * cofactor4x4(m, 0, i);
		i++;
	}
	return (d);
}

t_matrix	matrix4x4_inverse(t_matrix *m)
{
	t_matrix	m2;
	t_matrix	inverse;
	double		d;
	int			x;
	int			y;

	if (determinant4x4(m) == 0)
		return (*m);
	d = determinant4x4(m);
	y = 0;
	inverse = new_matrix();
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			inverse.m[y][x] = cofactor4x4(m, y, x) / d;
			x++;
		}
		y++;
	}
	m2 = matrix_transpose(&inverse);
	return (m2);
}
