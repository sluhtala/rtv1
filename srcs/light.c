#include "rtv_1.h"
#include <stdio.h>
void	putcol(t_color c)
{
	printf("color %f %f %f %f\n\n", c.r, c.g ,c.b, c.a);
}

t_color		lighting(t_material material, t_light light,t_vec4 point,t_vec4 eyev,t_vec4 normalv)
{
	t_color effective_color;
	t_vec4 lightv;
	t_color ambient;
	t_color diffuse;
	t_color specular;
	t_vec4 reflectv;
	double light_dot_normal;
	double reflect_dot_eye;
	double factor;

	effective_color = color_multiply(material.color, light.intensitivity);	
	lightv = vec4_normalize(vec4_substract(light.position, point));
	ambient = color_multiply_1(effective_color, material.ambient);
	light_dot_normal = vec4_dot(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse = new_color(0);
		specular = new_color(0);
	}
	else
	{
		diffuse = color_multiply_1(effective_color, material.diffuse * light_dot_normal);
		reflectv = reflect(vec4_multiply_1(lightv, -1.0), normalv);
		reflect_dot_eye = vec4_dot(reflectv, eyev);
		if (reflect_dot_eye <= 0)
		{
			specular = new_color(0);
		}
		else
		{
			factor = pow(reflect_dot_eye, material.shininess);
			specular = color_multiply_1(light.intensitivity, material.specular);
			specular = color_multiply_1(specular, factor);
		}
	}
	t_color result;
	result = color_add(color_add(ambient, diffuse), specular);
	return (result);
}

t_material	*material()
{
	t_material *m;

	m = (t_material*)malloc(sizeof(t_material));
	m->color = new_color(WHITE);
	m->ambient = 0.1;
	m->diffuse = 0.9;
	m->specular = 0.9;
	m->shininess = 200.0;	
	return (m);
}

t_light		point_light(t_vec4 position, t_color intensitivity)
{
	t_light l;

	l.position = position;
	l.intensitivity = intensitivity;
	return (l);
}
