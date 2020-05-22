#include "rtv_1.h"

t_3x3matrix	*submatrix4x4(t_4x4matrix *m, int row, int column)
{
	int			yx1[2];
	int			yx2[2];
	t_3x3matrix	*result;

	result = (t_3x3matrix*)malloc(sizeof(t_3x3matrix));
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
			result->m[yx2[0]][yx2[1]] = m->m[yx1[0]][yx1[1]]; 	
			yx1[1]++;
			yx2[1]++;
		}
		yx1[0]++;
		yx2[0]++;
	}
	return (result);
}

t_2x2matrix	*submatrix3x3(t_3x3matrix *m, int row, int column)
{
	int			yx1[2];
	int			yx2[2];
	t_2x2matrix	*result;

	result = (t_2x2matrix*)malloc(sizeof(t_2x2matrix));
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
			result->m[yx2[0]][yx2[1]] = m->m[yx1[0]][yx1[1]]; 	
			yx1[1]++;
			yx2[1]++;
		}
		yx1[0]++;
		yx2[0]++;
	}
	return (result);
}
