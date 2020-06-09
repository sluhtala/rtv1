/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:53:13 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 14:55:33 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

void			set_identity_matrix(t_matrix *m)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			m->m[y][x] = 0;
			if (x == y)
				m->m[y][x] = 1;
			x++;
		}
		y++;
	}
}

t_matrix		new_matrix(void)
{
	t_matrix m;

	m.inverse = &matrix4x4_inverse;
	m.transpose = &matrix_transpose;
	m.multiply = &matrix_multiply;
	m.multiply_vec = &matrix_vec4_multiply;
	m.putmatrix = &put4x4matrix;
	m.identity = &set_identity_matrix;
	m.identity(&m);
	return (m);
}
