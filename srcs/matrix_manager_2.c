#include "rtv_1.h"

/*
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
*/

double		**submatrix(double **m, int size, int row, int column)
{
	int			yx1[2];
	int			yx2[2];
	double  	**result;

	result = new_matrix(size - 1, size - 1);
	yx1[0] = 0;
	yx2[0] = 0;
	while (yx2[0] < size - 1)
	{
		yx1[1] = 0;
		yx2[1] = 0;
		if (yx1[0] == row)
			yx1[0]++;
		while (yx2[1] < size - 1)
		{
			if (yx1[1] == column)
				yx1[1]++;
			result[yx2[0]][yx2[1]] = m[yx1[0]][yx1[1]]; 	
			yx1[1]++;
			yx2[1]++;
		}
		yx1[0]++;
		yx2[0]++;
	}
	return (result);
}

double	determinant(double **m, int size)
{
	int i;
	double d;

	i = 0;
	d = 0.0;

	if (size == 2)
		return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
	while (i < size)
	{
		d = d + m[0][i] * matrix_cofactor(m, size, 0, i);
		i++;
	}
	return (d);
}

double	matrix_minor(double **m, int size, int row, int column)
{
	double d;
	double  **m2;
	m2 = submatrix(m, size, row, column);
	d = determinant(m2, size - 1);
	delete_matrix(&m2, size - 1);
	return (d);
}

double	matrix_cofactor(double **m, int size, int row, int column)
{
	if ((row + column) % 2 == 0)
	{
		return (matrix_minor(m, size, row, column));
	}
	else
	{
		return (-matrix_minor(m, size, row, column));
	}
}

double	 **matrix_transpose(double **m, int size)
{
	double	**result;
	int x;
	int y;

	y = 0;
	result = new_matrix(size, size);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			result[y][x] = m[x][y];
			x++;
		}
		y++;
	}
	return (result);
}
