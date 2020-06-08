#ifndef SL_COLORS_H
# define SL_COLORS_H

typedef unsigned char	t_u_int8;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	double		a;
}				t_color;

typedef struct	s_icolor
{
	t_u_int8 r;
	t_u_int8 g;
	t_u_int8 b;
	t_u_int8 a;
}				t_icolor;

t_color			color_multiply(t_color c1, t_color c2);
t_color			color_multiply_1(t_color c1, double n);
t_color			color_add(t_color c1, t_color c2);
t_color			color_substract(t_color c1, t_color c2);
t_color			new_color(int hex);
t_icolor		color_to_uint8(t_color color);
void			putcol(t_color c);

#endif
