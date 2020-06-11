/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:42:32 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:48:56 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

t_camera	new_camera(int hsize, int vsize, double fov)
{
	t_camera	cam;
	double		half_view;
	double		aspect;

	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.transform = new_matrix();
	cam.inverse = new_matrix();
	cam.field_of_view = fov;
	half_view = tan(cam.field_of_view / 2.0);
	aspect = cam.hsize / (double)cam.vsize;
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
	cam.pixel_size = (cam.half_width * 2.0) / cam.hsize;
	return (cam);
}

/*
** double xyxy = xoffset, yoffset, worldx, worldy
*/

t_ray		ray_for_pixel(t_camera camera, int px, int py)
{
	double		xyxy[4];
	t_matrix	temp;
	t_vec4		pixel;
	t_vec4		origin;
	t_vec4		direction;

	xyxy[0] = (px + 0.5) * camera.pixel_size;
	xyxy[1] = (py + 0.5) * camera.pixel_size;
	xyxy[2] = camera.half_width - xyxy[0];
	xyxy[3] = camera.half_height - xyxy[1];
	temp = camera.inverse;
	pixel = matrix_vec4_multiply(temp, point(xyxy[2], xyxy[3], -1));
	origin = matrix_vec4_multiply(temp, point(0, 0, 0));
	direction = vec4_normalize(vec4_substract(pixel, origin));
	return (new_ray(origin, direction));
}

static void	track_percent(int y, int vsize)
{
	double percent;

	percent = 100 * y / vsize;
	ft_printf("\rImage done: %d%%", (int)percent);
	if (percent >= 100)
		ft_printf("\nImage rendered!\n");
}

t_color		**render(t_camera camera, t_world *world)
{
	t_color	**pixels;
	t_ray	r;
	int		x;
	int		y;

	y = 0;
	camera.inverse = camera.transform.inverse(&camera.transform);
	if (!(pixels = (t_color**)malloc(sizeof(t_color*) * camera.vsize)))
		error_manager("MALLOC error");
	while (y < camera.vsize)
	{
		x = 0;
		if (!(pixels[y] = (t_color*)malloc(sizeof(t_color) * camera.hsize)))
			error_manager("MALLOC error");
		while (x < camera.hsize)
		{
			r = ray_for_pixel(camera, x, y);
			pixels[y][x++] = color_at(world, r);
		}
		y++;
		track_percent(y, camera.vsize);
	}
	return (pixels);
}
