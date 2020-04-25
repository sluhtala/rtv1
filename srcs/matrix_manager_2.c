#include "rtv_1.h"

double	minor3x3(double m[3][3], int row, int column)
{
	double d;
	t_2x2matrix m2;

	m2 = submatrix3x3(m, row, column);
	d = determinant2x2(m2.m);
	return (d);
}

double	minor4x4(double m[4][4], int row, int column)
{
	double d;
	t_3x3matrix m2;

	m2 = submatrix4x4(m, row, column);
	d = determinant3x3(m2.m);
	return (d);
}

double	cofactor3x3(double m[3][3], int row, int column)
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

double	cofactor4x4(double m[4][4], int row, int column)
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

t_4x4matrix matrix_transpose(double m[4][4])
{
	t_4x4matrix result;
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			result.m[y][x] = m[x][y];
			x++;
		}
		y++;
	}
	return (result);
}
