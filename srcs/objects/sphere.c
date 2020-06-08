#include "rtv_1.h"


static t_vec4	get_discriminant(t_vec4 sphere_to_ray, t_ray *ray)
{
	t_vec4 d;

	d.x = vec4_dot(ray->direction, ray->direction);
	d.y = 2.0 * vec4_dot(ray->direction, sphere_to_ray);
	d.z = vec4_dot(sphere_to_ray, sphere_to_ray) - 1.0;
	d.w = (d.y * d.y) - 4.0 * d.x * d.z;
	return (d);
}

t_xs	intersect_sphere(t_sphere *s, t_ray r)
{
	t_xs xs;
	t_vec4 d;
	t_vec4 sphere_to_ray;

	xs = xs_init();
	sphere_to_ray = vec4_substract(r.origin, point(0, 0, 0));
	d = get_discriminant(sphere_to_ray, &r);
	if (d.w < 0)
	{
		xs.i[0].count = 0;
		return (xs);
	}
	xs.i[0].count = 2;
	xs.i[0].t = (-d.y - sqrt(d.w)) / (2.0 * d.x);
	xs.i[1].t = (-d.y + sqrt(d.w)) / (2.0 * d.x);
	xs.i[0].object = (t_shape*)s;
	xs.i[1].object = (t_shape*)s;
	xs.i[0].count = 2;
	xs.i[1].count = 2;
	xs.i[0].null = 0;
	xs.i[1].null = 0;
	return (xs);
}

t_vec4		sphere_normal_at(t_vec4 pnt)
{
	return (vec4_substract(pnt, point(0,0,0)));
}



t_sphere	new_sphere(int id)
{
	t_sphere	s;
	
	s.type = SPHERE;
	s.transform = new_matrix();
	s.id = id;
	s.transform.identity(&s.transform);
	s.material = new_material();
	return (s);
}
