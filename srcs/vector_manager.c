#include "rtv_1.h"

t_vec4	vec4_cros(t_vec4 v1, t_vec4 v2)
{
	t_vec4 c;

	c.x = v1.y * v2.z - v1.z * v2.y;
	c.y = v1.z * v2.x - v1.x * v2.z;
	c.z = v1.x * v2.y - v1.y * v2.x;
	return (c);
}

double	vec4_dot(t_vec4 v1, t_vec4 v2)
{
	double dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	return (dot);
}

double	vec4_magnitude(t_vec4 v)
{
	double m;

	m = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (m);
}

t_vec4	vec4_normalize(t_vec4 v)
{
	double m;

	m = vec4_magnitude(v);
	v.x /= m;
 	v.y /= m;
 	v.z /= m;
	return (v);
}

t_vec4	vec4_divide(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	if (v2.x == 0 || v2.y == 0 || v2.z == 0)
		return (v2);
	result.x = v1.x / v2.x;
	result.y = v1.y / v2.y;
	result.z = v1.z / v2.z;
	return (result);
}

t_vec4	vec4_multiply_2(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	result.x = v1.x * v2.x;
	result.y = v1.y * v2.y;
	result.z = v1.z * v2.z;
	return (result);
}

t_vec4	vec4_multiply_1(t_vec4 v1, double d)
{
	t_vec4 result;

	result.x = v1.x * d;
	result.y = v1.y * d;
	result.z = v1.z * d;
	return (result);
}

t_vec4	vec4_substract(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

t_vec4	vec4_add(t_vec4 v1, t_vec4 v2)
{
	t_vec4 result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

int		vec4_compare(t_vec4 v1, t_vec4 v2)
{
	double epsilon;

	epsilon = 0.000001;
	if (fabs(v1.x - v2.x) < epsilon)
	{
		if (fabs(v1.y - v2.y) < epsilon)
		{
			if (fabs(v1.z - v2.z) < epsilon)
				return (1);
		}
	}
	return (0);
}

t_vec4	new_vec4(double x, double y, double z, double w)
{
	t_vec4 v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}
