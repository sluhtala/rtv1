#include "rtv_1.h"

t_vec4 point(double x, double y, double z)
{
	return (new_vec4(x, y, z, 1.0));
}

t_vec4 vector(double x, double y, double z)
{
	return (new_vec4(x, y, z, 0.0));
}
