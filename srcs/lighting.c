#include "rtv_1.h"

t_color		lighting(t_material material, t_light light,t_vec4 point,t_vec4 eyev,t_vec4 normalv, int in_shadow)
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
	if (in_shadow)
		result = ambient;
	return (result);
}
