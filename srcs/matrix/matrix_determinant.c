#include "rtv_1.h"

double	determinant2x2(t_2x2matrix *m)
{
	double d;
	
	d = m->m[0][0] * m->m[1][1] - m->m[0][1] * m->m[1][0];
	return (d);
}

double	determinant3x3(t_3x3matrix *m)
{
	int i;
	double d;

	i = 0;
	d = 0.0;
	while (i < 3)
	{
		d = d + m->m[0][i] * cofactor3x3(m, 0, i);
		i++;
	}
	return (d);
}

double	determinant4x4(t_4x4matrix *m)
{
	int i;
	double d;

	i = 0;
	d = 0.0;
	while (i < 4)
	{
		d = d + m->m[0][i] * cofactor4x4(m, 0, i);
		i++;
	}
	return (d);
}

t_4x4matrix	new_matrix(double m[4][4])
{
	int x;
	int y;
	t_4x4matrix m2;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			m2.m[y][x] = m[y][x];
			x++;
		}
		y++;
	}
	return (m2);
}

t_4x4matrix *matrix4x4_inverse(t_4x4matrix *m)
{
	t_4x4matrix *m2;
	t_4x4matrix *inverse;
	double d;
	int x;
	int y;

	if (determinant4x4(m) == 0)
		return (m);
	d = determinant4x4(m);
	y = 0;
	inverse = new_4x4matrix();
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			inverse->m[y][x] = cofactor4x4(m, y, x) / d;
			x++;
		}
		y++;
	}
	m2 = matrix_transpose(inverse);
	free(inverse);
	return (m2);
}
