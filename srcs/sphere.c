#include "rtv_1.h"

void	put_vec(t_vec4 v)
{
	ft_printf("vec: %.1f, %.1f, %.1f\n", v.x, v.y, v.z);	
}

double		**set_transform(t_sphere s, double **transformation)
{
	double	**m;

	m = matrix_multiply(s.transform, transformation);
	delete_matrix(&transformation, 4);
	return (m);
}

t_vec4		normal_at(t_sphere s, t_vec4 world_point )
{
	t_vec4 object_point;
	t_vec4 object_normal;
	t_vec4 world_normal;

	object_point = matrix_vec4_multiply(matrix_inverse(
		s.transform, 4), world_point);
	object_normal = vec4_substract(object_point, new_vec4(0, 0, 0, 1));
	world_normal = matrix_vec4_multiply(matrix_transpose(
		matrix_inverse(s.transform, 4), 4), object_normal);
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

t_sphere	new_sphere(int id)
{
	t_sphere	s;

	s.id = id;
	s.transform = new_matrix(4, 4);
	s.transform[0][0] = 1; 
	s.transform[0][1] = 0;
	s.transform[0][2] = 0;
	s.transform[0][3] = 0;
	s.transform[1][0] = 0;
	s.transform[1][1] = 1;
	s.transform[1][2] = 0;
	s.transform[1][3] = 0;
	s.transform[2][0] = 0;
	s.transform[2][1] = 0;
	s.transform[2][2] = 1;
	s.transform[2][3] = 0;
	s.transform[3][0] = 0;
	s.transform[3][1] = 0;
	s.transform[3][2] = 0;
	s.transform[3][3] = 1;
	s.material = material();
	return (s);
}
/*
int main()
{
	t_vec4 normal;
	t_vec4 point;
	t_sphere s;
	t_vec4 r;

	s = new_sphere(1);
	point = new_vec4(sqrt(2.0)/2.0,sqrt(2.0)/2.0,0,1);
	normal = normal_at(s, point);
	r = reflect(new_vec4(0,-1,0,0), normal);
	put_vec(r);	

	return (0);
}
*/
