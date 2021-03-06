/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:13:29 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:14:02 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

t_vec4	point(double x, double y, double z)
{
	return (new_vec4(x, y, z, 1.0));
}

t_vec4	vector(double x, double y, double z)
{
	return (new_vec4(x, y, z, 0.0));
}
