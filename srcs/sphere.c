#include "rtv_1.h"

void	put_vec(t_vec4 v)
{
	ft_printf("vec: %.1f, %.1f, %.1f\n", v.x, v.y, v.z);	
}

void	set_transform(t_sphere *s, t_matrix transformation)
{
	t_matrix m;
	
	m = s->transform.multiply(s->transform, transformation);
	s->transform = m;
}

t_vec4		normal_at(t_sphere *s, t_vec4 world_point)
{
	t_vec4 object_point;
	t_vec4 object_normal;
	t_vec4 world_normal;
	t_matrix mat;
	t_matrix mat2;
	
	mat = s->transform.inverse(&s->transform);
	object_point = matrix_vec4_multiply(mat, world_point);
	object_normal = vec4_substract(object_point, point(0, 0, 0));	
	mat2 = mat.transpose(&mat);
	world_normal = matrix_vec4_multiply(mat2, object_normal);
	world_normal.w = 0;
	return(vec4_normalize(world_normal));		
}

t_vec4 reflect(t_vec4 in, t_vec4 normal)
{
	t_vec4 r;

	r = vec4_multiply_1(normal, 2.0);
	r = vec4_multiply_1(r, vec4_dot(in, normal));
	r = vec4_substract(in, r);
	return (r);
}


void		delete_sphere(t_sphere sphere)
{
	return ;
	//	if ((sphere).transform != NULL)
	//	delete_matrix(sphere.transform);
}

t_sphere	new_sphere(int id)
{
	t_sphere	s;

	s.transform = new_matrix();
	s.id = id;
	s.transform.identity(&s.transform);
	s.material = new_material();
	return (s);
}
