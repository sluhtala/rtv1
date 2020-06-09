/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:01:02 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 16:01:55 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "rtv_1.h"

typedef struct	s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}				t_material;

typedef struct	s_camera
{
	int			hsize;
	int			vsize;
	double		field_of_view;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	transform;
}				t_camera;

typedef struct	s_light
{
	t_vec4		position;
	t_color		intensitivity;
}				t_light;

typedef struct	s_shape
{
	char		type[10];
	t_matrix	transform;
	t_material	material;
	t_ray		saved_ray;
}				t_shape;

typedef struct	s_shape_child
{
	t_shape shape;
}				t_shape_child;

typedef struct	s_sphere
{
	t_shape		shape;
	int			id;
}				t_sphere;

#endif
