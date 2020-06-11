/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:37:27 by sluhtala          #+#    #+#             */
/*   Updated: 2020/06/09 15:36:32 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_1.h"
#include <fcntl.h>
#include <sys/types.h>

void	write_header(int file, int w, int h)
{
	char *text;

	write(file, "P3\n", 3);
	text = ft_itoa(w);
	write(file, text, ft_strlen(text));
	write(file, " ", 1);
	free(text);
	text = ft_itoa(h);
	write(file, text, ft_strlen(text));
	free(text);
	write(file, "\n", 1);
	write(file, "255\n", 4);
}

char	*get_line(t_image img, int x, int y)
{
	char *t;
	char *temp;
	char *line;

	t = ft_itoa((int)(255.0 * img.pixels[y][x].r));
	line = ft_strjoin(t, " ");
	free(t);
	t = ft_itoa((int)(255.0 * img.pixels[y][x].g));
	temp = ft_strjoin(line, t);
	free(line);
	free(t);
	line = ft_strjoin(temp, " ");
	free(temp);
	t = ft_itoa((int)(255.0 * img.pixels[y][x].b));
	temp = ft_strjoin(line, t);
	free(line);
	free(t);
	line = ft_strjoin(temp, " ");
	free(temp);
	return (line);
}

void	write_data(int file, t_image img, t_data *data)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			line = get_line(img, x, y);
			write(file, line, ft_strlen(line));
			free(line);
			if (x != 0 && x % 5 == 0)
			{
				write(file, "\n", 1);
			}
			x++;
		}
		write(file, "\n", 1);
		y++;
	}
	write(file, "\n", 1);
}

void	img_to_ppm(t_image img, char *file_name, t_data *data)
{
	int file;

	ft_printf("Saving to image.ppm...\n");
	file = open(file_name, O_RDWR | O_CREAT, 777);
	if (file == -1)
	{
		ft_printf("Error saving image.\n");
		return ;
	}
	write_header(file, data->width, data->height);
	write_data(file, img, data);
	ft_printf("Image saved\n");
	close(file);
}
