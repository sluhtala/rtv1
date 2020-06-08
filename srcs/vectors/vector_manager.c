#include "rtv_1.h"


int		vec4_compare(t_vec4 v1, t_vec4 v2)
{
	double epsilon;

	epsilon = EPSILON;
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
