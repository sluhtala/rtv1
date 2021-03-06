/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_putmatrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 14:58:50 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:00:02 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"

void	put4x4matrix(t_matrix m)
{
	int y;

	y = 0;
	while (y < 4)
	{
		ft_printf("%6.3f |  %6.3f | %6.3f |  %6.3f \n",
			m.m[y][0], m.m[y][1], m.m[y][2], m.m[y][3]);
		if (y < 3)
			ft_printf("------------------------------------\n");
		y++;
	}
}

void	put3x3matrix(t_matrix m)
{
	int y;

	y = 0;
	while (y < 3)
	{
		ft_printf("%6.2f | %6.2f | %6.2f\n", m.m[y][0],
			m.m[y][1], m.m[y][2]);
		if (y < 2)
			ft_printf("---------------------\n");
		y++;
	}
}

void	put2x2matrix(t_matrix m)
{
	int y;

	y = 0;
	while (y < 2)
	{
		ft_printf("%6.2f | %6.2f\n", m.m[y][0], m.m[y][1]);
		if (y < 1)
			ft_printf("------------------\n");
		y++;
	}
}
