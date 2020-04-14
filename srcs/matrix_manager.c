#include "rtv_1.h"

t_vec4	matrix_vec4_multiply(double	m[4][4], t_vec4 p)
{
	t_vec4		p2;
	int			x;
	int			y;

	p2.x = m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z + m[0][3] * p.w;
	p2.y = m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z + m[1][3] * p.w;
	p2.z = m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z + m[2][3] * p.w;
	p2.w = m[3][0] * p.x + m[3][1] * p.y + m[3][2] * p.z + m[3][3] * p.w;
	return (p2);
}

t_4x4matrix	matrix_multiply(double m1[4][4], double m2[4][4])
{
	t_4x4matrix	m;
	int			x;
	int			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			m.m[y][x] = m1[y][0] * m2[0][x] + m1[y][1] * m2[1][x] +
				m1[y][2] * m2[2][x] + m1[y][3] * m2[3][x];
			x++;
		}
		y++;
	}
	return (m);
}

int	matrix_2x2_compare(double m1[2][2], double m2[2][2])
{
	int x;
	int y;

	y = 0;
	while (y < 2)
	{
		x = 0;
		while (x < 2)
		{
			if (m1[y][x] != m2[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	matrix_3x3_compare(double m1[3][3], double m2[3][3])
{
	int x;
	int y;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (m1[y][x] != m2[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	matrix_4x4_compare(double m1[4][4], double m2[4][4])
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (m1[y][x] != m2[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
