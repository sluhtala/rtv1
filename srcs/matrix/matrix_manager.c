#include "rtv_1.h"

t_vec4	matrix_vec4_multiply(t_4x4matrix *m, t_vec4 p)
{
	t_vec4		p2;
	int			x;
	int			y;

	p2.x = m->m[0][0] * p.x + m->m[0][1] * p.y + m->m[0][2] * p.z + m->m[0][3] * p.w;
	p2.y = m->m[1][0] * p.x + m->m[1][1] * p.y + m->m[1][2] * p.z + m->m[1][3] * p.w;
	p2.z = m->m[2][0] * p.x + m->m[2][1] * p.y + m->m[2][2] * p.z + m->m[2][3] * p.w;
	p2.w = m->m[3][0] * p.x + m->m[3][1] * p.y + m->m[3][2] * p.z + m->m[3][3] * p.w;
	return (p2);
}

t_4x4matrix	*matrix_multiply(t_4x4matrix *m1, t_4x4matrix *m2)
{
	t_4x4matrix	*m;
	int			x;
	int			y;

	y = 0;
	m = new_4x4matrix();
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			m->m[y][x] = m1->m[y][0] * m2->m[0][x] + m1->m[y][1] * m2->m[1][x] +
				m1->m[y][2] * m2->m[2][x] + m1->m[y][3] * m2->m[3][x];
			x++;
		}
		y++;
	}
	return (m);
}

int	matrix_2x2_compare(t_2x2matrix *m1, t_2x2matrix *m2)
{
	int x;
	int y;

	y = 0;
	while (y < 2)
	{
		x = 0;
		while (x < 2)
		{
			if (m1->m[y][x] != m2->m[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	matrix_3x3_compare(t_3x3matrix *m1, t_3x3matrix *m2)
{
	int x;
	int y;

	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			if (m1->m[y][x] != m2->m[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	matrix_4x4_compare(t_4x4matrix *m1, t_4x4matrix *m2)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (m1->m[y][x] != m2->m[y][x])
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void		delete_4x4matrix(t_4x4matrix **m)
{
	free(*m);
}

void	set_identity_matrix(t_4x4matrix *m)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while(x < 4)
		{
			m->m[y][x] = 0;
			if (x == y)
				m->m[y][x] = 1;
			x++;
		}
		y++;
	}
}

t_4x4matrix		*new_4x4matrix()
{
	t_4x4matrix *m;

	if (!(m = (t_4x4matrix*)malloc(sizeof(t_4x4matrix))))
		error_manager("MALLOC error");
	return (m);
}
