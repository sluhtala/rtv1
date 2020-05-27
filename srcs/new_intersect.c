#include "rtv_1.h"

void	sort_intersect(t_intersection *i, int count)
{
	int j;
	t_intersection temp;

	j = 0;
	while (j + 1 < count)
	{
		if (i[j].t > i[j + 1].t)
		{
			temp = i[j];
			i[j] = i[j + 1];
			i[j + 1] = temp;
			j = 0;
		}
		else
			j++;
	}
}

static t_intersection intersection(double t, void *object)
{
	t_intersection i;

	i.t = t;
	i.object = object;
	return (i);
}

static t_vec4	get_discriminant(t_vec4 sphere_to_ray, t_ray *ray)
{
	t_vec4 d;

	d.x = vec4_dot(ray->direction, ray->direction);
	d.y = 2 * vec4_dot(ray->direction, sphere_to_ray);
	d.z = vec4_dot(sphere_to_ray, sphere_to_ray) - 1;
	d.w = (d.y * d.y) - 4 * d.x * d.z;
	return (d);
}

t_intersection *intersect_world(t_world *w, t_ray r)
{
	t_intersection *xs;
	t_intersection *tmp;
	int i;
	int s;

	s = 0;
	i = 0;
	xs = malloc(sizeof(t_intersection) * (w->objectamount * 2));
	while (s < w->objectamount)
	{
		if ((tmp = intersect((w->spheres)[s], r)))
		{
			xs[i] = tmp[0];
			xs[i + 1] = tmp[1];
			free(tmp);
			i += 2;
		}
		s++;
	}
	xs[0].count = i;
	sort_intersect(xs, i);
	return (xs);
}

t_intersection *intersect(t_sphere *s, t_ray r)
{
	t_intersection *xs;
	t_vec4 d;
	t_vec4 sphere_to_ray;
	t_ray r2;

	r2 = transform_ray(r, matrix4x4_inverse(s->transform));
	sphere_to_ray = vec4_substract(r2.origin, point(0, 0, 0));
	d = get_discriminant(sphere_to_ray, &r2);
	if (d.w < 0)
		return (NULL);
	xs = (t_intersection*)malloc(sizeof(t_intersection) * 2);
	xs[0].count = 2;
	xs[0].t = (-d.y - sqrt(d.w)) / (2 * d.x);
	xs[1].t = (-d.y + sqrt(d.w)) / (2 * d.x);
	xs[0].object = s;
	xs[1].object = s;
	xs[0].count = 2;
	xs[1].count = 2;
	sort_intersect(xs, 2);
	return (xs);
}

t_intersection *hit(t_intersection *inter)
{
	int i;
	int count;
	t_intersection *smallest;

	if (inter == NULL)
		return (NULL);
	count = inter[0].count;
	i = 0;
	smallest = NULL;
	while (i < count)
	{
		if (smallest == NULL && inter[i].t >= 0)
			smallest = inter + i;
		else if (smallest != NULL && smallest->t > inter[i].t)
			smallest = inter + i;
		i++;
	}
	return (smallest);
}
