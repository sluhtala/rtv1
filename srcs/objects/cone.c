#include "rtv_1.h"

static int	check_cap(t_ray *r, double t, double rad)
{
	double x;
	double z;

	x = r->origin.x + t * r->direction.x;
	z = r->origin.z + t * r->direction.z;
	return ((x * x +  z * z) <= rad);
}

static void	intersect_caps(t_xs *xs, t_cone *c, t_ray *r, int i)
{
	double t;

	if(c->closed == 0 || fabs(r->direction.y) < EPSILON)
		return ;
	t = (c->minimum - r->origin.y) / r->direction.y;
	if (check_cap(r, t, fabs(c->minimum)))
	{
		xs->i[i].t = t; 
		xs->i[i].object = (t_cylinder*)c;
		xs->i[i].null = 0;
		xs->i[0].count++;
		i++; 
	}
	t = (c->maximum - r->origin.y) / r->direction.y;
	if (check_cap(r, t, fabs(c->maximum)))
	{
		xs->i[i].t = t; 
		xs->i[i].object = (t_cylinder*)c;
		xs->i[i].null = 0;
		xs->i[0].count++;
		i++; 
	}
}

t_xs	intersect_cone(t_cone *c, t_ray r)
{
	t_xs	xs;
	double	t[2];
	t_vec4	d;
	double	y[2];
	int 	i;

	xs = xs_init();	
	d.x = pow(r.direction.x, 2) - pow(r.direction.y, 2) + pow(r.direction.z, 2);
	d.y = 2 * r.origin.x * r.direction.x - 2 * r.origin.y *
		r.direction.y + 2 * r.origin.z * r.direction.z;
	d.z = r.origin.x * r.origin.x - r.origin.y * r.origin.y + r.origin.z * r.origin.z;
	if (d.w < 0)
		return (xs);
	if (d.x == 0 && d.y != 0)
	{
		t[0] = -d.z / 2 * d.y;
		t[1] = -d.z / 2 * d.y;
	}
	else
	{
		d.w = d.y * d.y - 4 * d.x * d.z;
		t[0] = (-d.y - sqrt(d.w)) / (2 * d.x);
		t[1] = (-d.y + sqrt(d.w)) / (2 * d.x);
	}
	y[0] = r.origin.y + t[0] * r.direction.y;
	i = 0;
	if (c->minimum < y[0] && y[0] < c->maximum)
	{
		xs.i[i].t = t[0];
		xs.i[i].object = (t_shape*)c;
		xs.i[i].null = 0;
		xs.i[0].count = i + 1;
		i++;
	}
	y[1] = r.origin.y + t[1] * r.direction.y;
	if (c->minimum < y[1] && y[1] < c->maximum)
	{
		xs.i[i].t = t[1];
		xs.i[i].object = (t_shape*)c;
		xs.i[i].null = 0;
		xs.i[0].count = i + 1;
		i++;
	}
	intersect_caps(&xs, c, &r, i);
	return (xs);
}

t_vec4		cone_normal_at(t_shape* shape, t_vec4 point)
{
	double dist;
	double y;
	dist = point.x * point.x + point.z * point.z;
	if (dist < 1 && point.y >= shape->maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && point.y <= shape->minimum + EPSILON)
		return (vector(0, 1, 0));
	y = sqrt(point.x * point.x + point.z * point.z);
	if (point.y > 0)
		y = -y;
	return (vector(point.x, y, point.z));
}

t_cone new_cone(int id)
{
	t_cylinder c;

	c.type = CONE;
	c.id = id;
	c.transform = new_matrix();
	c.material = new_material();	
	c.transform.identity(&c.transform);
	c.minimum = -INFINITY;
	c.maximum = INFINITY;
	c.closed = 1;
	return (c);
}
