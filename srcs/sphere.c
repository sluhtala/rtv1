#include "rtv_1.h"

void	put_vec(t_vec4 v)
{
	ft_printf("vec: %.1f, %.1f, %.1f\n", v.x, v.y, v.z);	
}

void	set_transform(t_sphere *s, t_4x4matrix *transformation)
{
	t_4x4matrix *m;

	m = matrix_multiply(s->transform, transformation);
	free(s->transform);
	s->transform = m;
	free(transformation);
}

t_vec4		normal_at(t_sphere *s, t_vec4 world_point)
{
	t_vec4 object_point;
	t_vec4 object_normal;
	t_vec4 world_normal;
	t_4x4matrix *mat;
	t_4x4matrix *mat2;
	
	mat = matrix4x4_inverse(s->transform);
	object_point = matrix_vec4_multiply(mat, world_point);
	object_normal = vec4_substract(object_point, point(0, 0, 0));
	
	mat2 = matrix_transpose(mat);
	world_normal = matrix_vec4_multiply(mat2, object_normal);
	world_normal.w = 0;
	free(mat2);
	free(mat);
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


void		delete_sphere(t_sphere **sphere)
{
	if (*sphere == NULL)
		return ;
	if ((*sphere)->transform != NULL)
		free((*sphere)->transform);
	free((*sphere)->material);
	free(*sphere);
}

t_sphere	*new_sphere(int id)
{
	t_sphere	*s;

	s = (t_sphere*)malloc(sizeof(t_sphere));
	s->transform = new_4x4matrix();
	s->id = id;
	set_identity_matrix(s->transform);
	s->material = material();
	return (s);
}
