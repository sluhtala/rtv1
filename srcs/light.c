#include "rtv_1.h"
#include <stdio.h>
void	putcol(t_color c)
{
	printf("color %f %f %f %f\n\n", c.r, c.g ,c.b, c.a);
}


t_material	new_material()
{
	t_material m;

	m.color = new_color(WHITE);
	m.ambient = 0.15;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;	
	return (m);
}

t_light		point_light(t_vec4 position, t_color intensitivity)
{
	t_light l;

	l.position = position;
	l.intensitivity = intensitivity;
	return (l);
}
