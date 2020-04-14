#include "rtv_1.h"

void	put4x4matrix(double m[4][4])
{
	int y;

	y = 0;
	while (y < 4)
	{
		ft_printf("%6.3f |  %6.3f | %6.3f |  %6.3f \n",
			m[y][0], m[y][1], m[y][2], m[y][3]);
		if (y < 3)
			ft_printf("------------------------------------\n");
		y++;
	}
}

void	put3x3matrix(double m[3][3])
{
	int y;

	y = 0;
	while (y < 3)
	{
		ft_printf("%6.2f | %6.2f | %6.2f\n", m[y][0], m[y][1], m[y][2]);
		if (y < 2)	
			ft_printf("---------------------\n");
		y++;
	}
}

void	put2x2matrix(double m[2][2])
{
	int y;

	y = 0;
	while (y < 2)
	{
		ft_printf("%6.2f | %6.2f\n", m[y][0], m[y][1]);
		if (y < 1)	
			ft_printf("------------------\n");
		y++;
	}
}
