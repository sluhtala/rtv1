#include "rtv_1.h"

t_3x3matrix	submatrix4x4(double m[4][4], int row, int column)
{
	int			yx1[2];
	int			yx2[2];
	t_3x3matrix	result;

	yx1[0] = 0;
	yx2[0] = 0;
	while (yx2[0] < 3)
	{
		yx1[1] = 0;
		yx2[1] = 0;
		if (yx1[0] == row)
			yx1[0]++;
		while (yx2[1] < 3)
		{
			if (yx1[1] == column)
				yx1[1]++;
			result.m[yx2[0]][yx2[1]] = m[yx1[0]][yx1[1]]; 	
			yx1[1]++;
			yx2[1]++;
		}
		yx1[0]++;
		yx2[0]++;
	}
	return (result);
}

t_2x2matrix	submatrix3x3(double m[3][3], int row, int column)
{
	int			yx1[2];
	int			yx2[2];
	t_2x2matrix	result;

	yx1[0] = 0;
	yx2[0] = 0;
	while (yx2[0] < 2)
	{
		yx1[1] = 0;
		yx2[1] = 0;
		if (yx1[0] == row)
			yx1[0]++;
		while (yx2[1] < 2)
		{
			if (yx1[1] == column)
				yx1[1]++;
			result.m[yx2[0]][yx2[1]] = m[yx1[0]][yx1[1]]; 	
			yx1[1]++;
			yx2[1]++;
		}
		yx1[0]++;
		yx2[0]++;
	}
	return (result);
}
