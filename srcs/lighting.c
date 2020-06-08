#include "rtv_1.h"

t_vec4 reflect(t_vec4 in, t_vec4 normal)
{
	t_vec4 r;

	r = vec4_multiply_1(normal, 2.0);
	r = vec4_multiply_1(r, vec4_dot(in, normal));
	r = vec4_substract(in, r);
	return (r);
}

static void	calculate_diff_spec(t_lighting *l)
{

		l->diffuse = color_multiply_1(l->effective_color, l->material->diffuse 
		* l->light_dot_normal);
		l->reflectv = reflect(vec4_multiply_1(l->lightv, -1.0), l->normalv);
		l->reflect_dot_eye = vec4_dot(l->reflectv, l->eyev);
		if (l->reflect_dot_eye <= 0)
			l->specular = new_color(0);
		else
		{
			l->factor = pow(l->reflect_dot_eye, l->material->shininess);
			l->specular = color_multiply_1(l->light.intensitivity, 
				l->material->specular);
			l->specular = color_multiply_1(l->specular, l->factor);
		}
}

t_color		lighting(t_lighting *l)
{
	l->effective_color = color_multiply(l->material->color, 
		l->light.intensitivity);	
	l->lightv = vec4_normalize(vec4_substract(l->light.position, 
		l->point));
	l->ambient = color_multiply_1(l->effective_color, 
		l->material->ambient);
	l->light_dot_normal = vec4_dot(l->lightv, l->normalv);
	if (l->in_shadow || l->light_dot_normal < 0)
		return (l->ambient);
	else
	{
		calculate_diff_spec(l);
	}
	return (color_add(color_add(l->ambient, l->diffuse), l->specular));
}
