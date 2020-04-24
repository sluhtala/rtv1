#include "rtv_1.h"

double 		**translate(double x, double y, double z)
{
	double **m;

	m = new_matrix(4, 4);
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = x;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = y;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = z;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);	
}

double		**scale(double x, double y, double z)
{
	double **m;

	m = new_matrix(4, 4);
	m[0][0] = x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = y;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = z;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);	
}

double		**rotate_x(double r)
{
	double **m;

	m = new_matrix(4, 4);
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = cos(r);
	m[1][2] = -sin(r);
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = sin(r);
	m[2][2] = cos(r);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);	
}

double		**rotate_y(double r)
{
	double **m;

	m = new_matrix(4, 4);
	m[0][0] = cos(r);
	m[0][1] = 0;
	m[0][2] = sin(r);
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = -sin(r);
	m[2][1] = 0;
	m[2][2] = cos(r);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);	
}

double		**rotate_z(double r)
{
	double **m;

	m = new_matrix(4, 4);
	m[0][0] = cos(r);
	m[0][1] = -sin(r);
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = sin(r);
	m[1][1] = cos(r);
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);	
}
