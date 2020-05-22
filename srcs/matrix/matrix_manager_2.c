#include "rtv_1.h"

double	minor3x3(t_3x3matrix *m, int row, int column)
{
	double d;
	t_2x2matrix *m2;

	m2 = submatrix3x3(m, row, column);
	d = determinant2x2(m2);
	free(m2);
	return (d);
}

double	minor4x4(t_4x4matrix *m, int row, int column)
{
	double d;
	t_3x3matrix *m2;

	m2 = submatrix4x4(m, row, column);
	d = determinant3x3(m2);
	if (m2)
		free(m2);
	return (d);
}

double	cofactor3x3(t_3x3matrix *m, int row, int column)
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

double	cofactor4x4(t_4x4matrix *m, int row, int column)
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

t_4x4matrix *matrix_transpose(t_4x4matrix *m)
{
	t_4x4matrix *result;
	int x;
	int y;

	result = new_4x4matrix();
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			result->m[y][x] = m->m[x][y];
			x++;
		}
		y++;
	}
	return (result);
}
