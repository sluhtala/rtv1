/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vectors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:02:47 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 16:03:00 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_VECTORS_H
# define SL_VECTORS_H

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

t_vec4			vec4_cros(t_vec4 v1, t_vec4 v2);
double			vec4_dot(t_vec4 v1, t_vec4 v2);
double			vec4_magnitude(t_vec4 v);
t_vec4			vec4_normalize(t_vec4 v);
t_vec4			vec4_divide(t_vec4 v1, t_vec4 v2);
t_vec4			vec4_multiply_2(t_vec4 v1, t_vec4 v2);
t_vec4			vec4_multiply_1(t_vec4 v1, double d);
t_vec4			vec4_substract(t_vec4 v1, t_vec4 v2);
t_vec4			vec4_add(t_vec4 v1, t_vec4 v2);
int				vec4_compare(t_vec4 v1, t_vec4 v2);
t_vec4			new_vec4(double x, double y, double z, double w);

#endif
