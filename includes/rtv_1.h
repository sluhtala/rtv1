
#ifndef RTV_1_H
#define RTV_1_H
#include <libft.h>
#include <ft_printf.h>
# include <math.h>
# include "mlx.h"
# include <pthread.h>
# define TITLE "RTV-1"
# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define SPACE_KEY 49
# define BLUE 0x0000ff
# define RED 0xff0000
# define GREEN 0x00ff00
# define GRAY 0x888888
# define DARKGRAY 0x222222
# define WHITE 0xffffff
# define WIDTH 1200
# define HEIGHT 720

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
}				t_mlx;

typedef struct	s_image
{
	void		*ptr;
	int			bit_pix;
	int			size_line;
	int			endian;
	char		*buf;
	t_color		**pixels;
}				t_image;

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

typedef	struct	s_triangle
{
	t_vec3		a;
	t_vec3		b;
	t_vec3		c;
	t_color		col;
}				t_triangle;

typedef struct	s_data
{
	t_mlx		mlx;
	t_image		img;
}				t_data;

int				input_manager(int key, t_data *data);
void			close_program(t_data *data);
void			image_to_window(t_data *data);

# endif
