#include "rtv_1.h"

t_camera new_camera(int hsize, int vsize, double fov)
{
	t_camera cam;
	t_4x4matrix *m;
	double half_view;
	double aspect;

	cam.hsize = hsize;
	cam.vsize = vsize;
	m = new_4x4matrix();
	set_identity_matrix(m);
	cam.transform = m;
	cam.field_of_view = fov;
	half_view = tan(cam.field_of_view / 2);
	aspect = cam.hsize / cam.vsize;
	if (aspect >= 1)
	{
		cam.half_width = half_view;
		cam.half_height = half_view / aspect;
	}
	else
	{
		cam.half_width = half_view / aspect;
		cam.half_height = half_view;
	}
	cam.pixel_size = (cam.half_width * 2) / cam.hsize;	
	return (cam);
}

t_ray ray_for_pixel(t_camera camera, int px, int py)
{
	double xoffset;
	double yoffset;
	double world_x;
	double world_y;

	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) *camera.pixel_size;
	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;
	
	t_vec4 pixel;
	pixel = matrix_vec4_multiply(matrix4x4_inverse(camera.transform), point(world_x, world_y, -1));
	t_vec4 origin;
	origin = matrix_vec4_multiply(matrix4x4_inverse(camera.transform), point(0,0,0));
	t_vec4 direction;
	direction = vec4_normalize(vec4_substract(pixel, origin));
	return (new_ray(origin, direction));
}

t_color		**render(t_camera camera, t_world *world)
{
	t_color **pixels;
	t_ray r;
	int x;
	int y;

	y = 0;
	pixels = (t_color**)malloc(sizeof(t_color*) * (camera.vsize));
	while (y < camera.vsize)
	{
		x = 0;
		pixels[y] = (t_color*)malloc(sizeof(t_color) * (camera.hsize));
		while (x < camera.hsize)
		{
			r = ray_for_pixel(camera, x, y);
			pixels[y][x] = color_at(world, r);
			x++;
		}
		y++;
	}
	return (pixels);
}
