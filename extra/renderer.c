#include "rtv_1.h"

t_color		get_color(double world_y, double world_x, t_sphere *s, t_light light)
{
	t_color color;
	t_ray	r;
	t_vec4 r_origin;
	t_vec4 pos;
	t_intersection *xs;
	t_intersection *hitt;
	t_vec4 o_point;
	t_vec4 normal;
	t_vec4 eye;

	pos = new_vec4(world_x, world_y, 10.0, 1);
	r_origin = point(0.0, 0.0, -7.0);
	color = new_color(0);
	r.origin = r_origin;
	r.direction = vec4_normalize(vec4_substract(pos, r_origin));
	xs = intersect(s, r);
	hitt = hit(xs);
	if (hitt)
	{
		o_point = position(r, hitt->t);
		normal = normal_at(hitt->object, o_point);
		eye = vec4_multiply_1(r.direction, -1);	
		color = lighting(*((t_sphere*)(hitt->object))->material, light, o_point, eye, normal);
	}
	if (xs)
		free(xs);
	return (color);
}

double	radi(double degree)
{
	return (M_PI * degree / 180.0); 
}

int	 sphere_test(t_data *data)
{
	int x;
	int y;
	double world_y;
	double world_x;
	double half;
	double pixel_s;
	t_sphere *sphere;
		
	t_light light;

	sphere = new_sphere(1);
	sphere->material->color = new_color(RED);
	light = point_light(point(-10.0, 10.0, 0.0), new_color(WHITE));
	pixel_s = 7.0 / WIDTH;
	half = 7.0 / 2.0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		world_y = half - pixel_s * y;
		while (x < WIDTH)
		{
			world_x = -half + pixel_s * x;
			data->img.pixels[y][x] = get_color(world_y, world_x, sphere, light);			
			x++;
		}
		y++;
	}
	delete_sphere(&sphere);
	return (1);
}
