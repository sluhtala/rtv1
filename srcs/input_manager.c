#include "rtv_1.h"

int		input_manager(int key, t_data *data)
{
	ft_putnbr(key);
	if (key == ESC_KEY || key == 12)
		close_program(data);
	if (key == SPACE_KEY)
		image_to_window(data);
	if (key == 1)
		img_to_ppm(data->img, "images/image.ppm");
	return (key);
}
