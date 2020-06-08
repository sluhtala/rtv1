#include "rtv_1.h"

t_color	color_multiply_1(t_color c1, double n)
{
	t_color result;

	result.r = c1.r * n;
	result.g = c1.g * n;
	result.b = c1.b * n;
	result.a = c1.a * n;
	return (result);
}

t_color	color_multiply(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r * c2.r;
	result.g = c1.g * c2.g;
	result.b = c1.b * c2.b;
	result.a = c1.a * c2.a;
	return (result);
}

t_color	color_substract(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r - c2.r;
	result.g = c1.g - c2.g;
	result.b = c1.b - c2.b;
	result.a = c1.a - c2.a;
	return (result);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color result;

	result.r = c1.r + c2.r;
	if (result.r > 1)
		result.r = 1;
	result.g = c1.g + c2.g;
	if (result.g > 1)
		result.g = 1;
	result.b = c1.b + c2.b;
	if (result.b > 1)
		result.b = 1;
	result.a = c1.a + c2.a;
	return (result);
}

t_color	new_color(int hex)
{
	t_color col;

	col.r = (double)(hex >> 16);
	col.g = (double)(hex >> 8 & 0xff);
	col.b = (double)(hex & 0xff);
	col.a = 0.0;
	col.r /= 255.0;
	col.g /= 255.0;
	col.b /= 255.0;

	return (col);
}
