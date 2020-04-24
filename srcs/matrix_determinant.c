#include "rtv_1.h"

/*
double	determinant2x2(double m[2][2])
{
	double d;
	
	d = m[0][0] * m[1][1] - m[0][1] * m[1][0];
	return (d);
}

double	determinant3x3(double m[3][3])
{
	int i;
	double d;

	i = 0;
	d = 0.0;
	while (i < 3)
	{
		d = d + m[0][i] * cofactor3x3(m, 0, i);
		i++;
	}
	return (d);
}

double	determinant4x4(double m[4][4])
{
	int i;
	double d;

	i = 0;
	d = 0.0;
	while (i < 4)
	{
		d = d + m[0][i] * cofactor4x4(m, 0, i);
		i++;
	}
	return (d);
}

t_4x4matrix	new_matrix_4x4(double m[4][4])
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
t_4x4matrix matrix4x4_inverse(double m[4][4])
{
	t_4x4matrix m2;
	double inverse[4][4];
	double d;
	int x;
	int y;

	if (determinant4x4(m) == 0)
		return (new_matrix_4x4(m));
	d = determinant4x4(m);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			inverse[y][x] = cofactor4x4(m, y, x) / d;
			x++;
		}
		y++;
	}
	m2 = matrix_transpose(inverse);
	return (m2);
}
*/
double		**matrix_inverse(double **m, int size)
{
	double  **m2;
	double **inverse;
	double d;
	int x;
	int y;
	if (determinant(m, size) == 0)
		return (NULL);
	inverse = new_matrix(size, size);
	d = determinant(m, size);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			inverse[y][x] = matrix_cofactor(m, size, y, x) / d;
			x++;
		}
		y++;
	}
	m2 = matrix_transpose(inverse, size);
	delete_matrix(&inverse, size);
	return (m2);
}
