/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:05:50 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:08:42 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

t_intersection	new_intersection(t_shape *object, double t, int count)
{
	t_intersection i;

	i.count = count;
	i.object = object;
	i.t = t;
	i.null = 0;
	return (i);
}

t_xs			xs_init(void)
{
	int		i;
	t_xs	xs;

	i = 0;
	while (i < MAX_INTERSECTION)
	{
		xs.i[i].count = 0;
		xs.i[i].null = 1;
		xs.i[i].t = -100;
		i++;
	}
	return (xs);
}

void			sort_intersect(t_intersection *xs, int count)
{
	int				j;
	t_intersection	temp;

	j = 0;
	while (j + 1 < count)
	{
		if (xs[j].t > xs[j + 1].t)
		{
			temp = xs[j];
			xs[j] = xs[j + 1];
			xs[j + 1] = temp;
			j = 0;
		}
		else
			j++;
	}
}

t_xs			intersect_world(t_world *w, t_ray r)
{
	t_xs	xs;
	t_xs	tmp;
	int		i;
	int		s;

	s = 0;
	i = 0;
	xs = xs_init();
	while (s < w->objectamount && s < MAX_INTERSECTION)
	{
		tmp = intersect(&w->shapes[s], r);
		if (tmp.i[0].null == 0)
		{
			xs.i[i] = tmp.i[0];
			if (tmp.i[0].count == 2)
				xs.i[i + 1] = tmp.i[1];
			i += tmp.i[0].count;
		}
		s++;
	}
	sort_intersect(xs.i, i);
	xs.i[0].count = i;
	return (xs);
}

t_intersection	*hit(t_xs *inter)
{
	int				i;
	int				count;
	t_intersection	*smallest;

	if (inter == NULL)
		return (NULL);
	count = inter->i[0].count;
	i = 0;
	smallest = NULL;
	while (i < count)
	{
		if (smallest == NULL && inter->i[i].t >= 0)
			smallest = inter->i + i;
		else if (smallest != NULL && smallest->t > inter->i[i].t)
			smallest = inter->i + i;
		i++;
	}
	return (smallest);
}
