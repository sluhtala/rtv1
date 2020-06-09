/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:44:54 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 13:45:30 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

static unsigned char	convert_uint8(double col)
{
	char new;

	if (col > 1.0)
		new = (unsigned char)255;
	else if (col < 0)
		new = 0;
	else
		new = (unsigned char)(col * 255);
	return (new);
}

t_icolor				color_to_uint8(t_color color)
{
	t_icolor new_color;

	new_color.r = convert_uint8(color.r);
	new_color.g = convert_uint8(color.g);
	new_color.b = convert_uint8(color.b);
	new_color.a = convert_uint8(color.a);
	return (new_color);
}
