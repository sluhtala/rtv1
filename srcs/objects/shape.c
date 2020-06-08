#include "rtv_1.h"

t_shape		test_shape()
{
	t_shape s;

	s.transform = new_matrix();
	s.material = new_material();
	return (s);	
}

t_vec4		local_normal_at(t_shape *shape, t_vec4 point)
{
	if (shape->type == SPHERE)
	{
		return (sphere_normal_at(point));
	}
	else if (shape->type == PLANE)
	{
		return (plane_normal_at());
	}
	else if (shape->type == CUBE)
	{
		return (cube_normal_at(point));
	}
	else if (shape->type == CYLINDER)
	{
		return (cylinder_normal_at((t_cube*)shape, point));
	}
	else if (shape->type == CONE)
	{
		return (cone_normal_at((t_cube*)shape, point));
	}
	return (vector(point.x, point.y, point.z));
}

t_vec4		normal_at(t_shape *shape, t_vec4 point)
{
	t_vec4 local_point;
	t_vec4 local_normal;
	t_vec4 world_normal;
	t_matrix inv;

	local_point = matrix_vec4_multiply(
		matrix4x4_inverse(&shape->transform), point);
	local_normal = local_normal_at(shape, local_point);
	inv = matrix4x4_inverse(&shape->transform);
	world_normal = matrix_vec4_multiply(
		matrix_transpose(&inv), local_normal);	
	world_normal.w = 0;
	return (vec4_normalize(world_normal));
}

void	set_transform(t_shape *shape, t_matrix transformation)
{
	t_matrix m;

	m = matrix_multiply(shape->transform, transformation);
	shape->transform = m;
}

t_xs	local_intersect(t_shape *shape, t_ray ray)
{
	t_xs xs;

	shape->saved_ray = ray;
	if (shape->type == SPHERE)
	{
		return (intersect_sphere((t_sphere*)shape, ray));
	}
	else if (shape->type == PLANE)
	{
		return (intersect_plane((t_plane*)shape, ray));
	}
	else if (shape->type == CUBE)
	{
		return (intersect_cube((t_cube*)shape, ray));
	}
	else if (shape->type == CYLINDER)
	{
		return (intersect_cylinder(shape, ray));
	}
	else if (shape->type == CONE)
	{
		return (intersect_cone(shape, ray));
	}
	xs = xs_init();
	return (xs);
}

t_xs	intersect(t_shape *shape, t_ray ray)
{
	t_ray local_ray;
	t_matrix invers;

	invers = shape->transform.inverse(&shape->transform);
	local_ray = transform_ray(ray, &invers);
	return (local_intersect(shape, local_ray));
}
