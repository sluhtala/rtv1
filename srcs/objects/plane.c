#include "rtv_1.h"

t_xs	intersect_plane(t_plane *p, t_ray r)
{
	t_xs xs;
	double t;

	xs = xs_init();	
	if (fabs(r.direction.y) < EPSILON)
	{
		xs.i[0].count = 0;
		return (xs);	
	}
	t = -r.origin.y / r.direction.y;
	xs.i[0].t = t;
	xs.i[0].count = 1;
	xs.i[0].object = (t_shape*)p;
	xs.i[0].null = 0;
	return (xs);
}

t_vec4		plane_normal_at()
{
	t_vec4 v;

	v = vector(0, 1, 0);
	return (v);		
}

t_plane new_plane(int id)
{
	t_plane p;

	p.type = PLANE;
	p.id = id;
	p.transform = new_matrix();
	p.material = new_material();	
	p.transform.identity(&p.transform);
//	p.inverse.identity(&p.inverse);
	return (p);
}
