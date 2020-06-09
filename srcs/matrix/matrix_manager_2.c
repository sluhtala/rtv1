/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_manager_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:57:21 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 14:58:33 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

double		minor3x3(t_matrix *m, int row, int column)
{
	double		d;
	t_matrix	m2;

	m2 = submatrix3x3(m, row, column);
	d = determinant2x2(&m2);
	return (d);
}

double		minor4x4(t_matrix *m, int row, int column)
{
	double		d;
	t_matrix	m2;

	m2 = submatrix4x4(m, row, column);
	d = determinant3x3(&m2);
	return (d);
}

double		cofactor3x3(t_matrix *m, int row, int column)
{
	if ((row + column) % 2 == 0)
	{
		return (minor3x3(m, row, column));
	}
	else
	{
		return (-minor3x3(m, row, column));
	}
}

double		cofactor4x4(t_matrix *m, int row, int column)
{
	if ((row + column) % 2 == 0)
	{
		return (minor4x4(m, row, column));
	}
	else
	{
		return (-minor4x4(m, row, column));
	}
}

t_matrix	matrix_transpose(t_matrix *m)
{
	t_matrix	result;
	int			x;
	int			y;

	result = new_matrix();
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			result.m[y][x] = m->m[x][y];
			x++;
		}
		y++;
	}
	return (result);
}
