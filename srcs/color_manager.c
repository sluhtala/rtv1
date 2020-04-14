#include "rtv_1.h"

t_color	color_multiply(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r * c2.r;
	result.g = c1.g * c2.g;
	result.b = c1.b * c2.b;
	return (result);
}

t_color	color_substract(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r - c2.r;
	result.g = c1.g - c2.g;
	result.b = c1.b - c2.b;
	return (result);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	return (result);
}

t_color	new_color(int hex)
{
	t_color col;

	col.r = hex >> 16;
	col.g = hex >> 8 & 0xff;
	col.b = hex & 0xff;
	col.a = 0;
	return (col);
}
