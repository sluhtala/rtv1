
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
# define WIDTH 500
# define HEIGHT 500

typedef struct	s_options
{
	int			simple;
}				t_options;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	double		a;
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

typedef struct	s_vec4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vec4;

typedef struct	s_ray
{
	t_vec4		origin;
	t_vec4		direction;
}				t_ray;

typedef	struct	s_inters
{
	int			count;
	double		t[2];
}				t_inters;


typedef struct	s_4x4matrix
{
	double		m[4][4];
}				t_4x4matrix;

typedef struct	s_2x2matrix
{
	double		m[2][2];
}				t_2x2matrix;

typedef struct	s_3x3matrix
{
	double		m[3][3];
}				t_3x3matrix;


typedef struct	s_light
{
	t_vec4		position;
	t_color		intensitivity;
}				t_light;

typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}				t_material;

typedef struct	s_sphere
{
	int			id;
	t_4x4matrix	transform;
	t_material	material;
}				t_sphere;

typedef struct	s_intersection
{
	t_sphere	object;
	double		t;
}				t_intersection;

typedef struct	s_data
{
	t_mlx		mlx;
	t_image		img;
	t_options	opt;
}				t_data;

int				input_manager(int key, t_data *data);
void			close_program(t_data *data);
void			image_to_window(t_data *data);
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
t_color			color_multiply(t_color c1, t_color c2);
t_color			color_dmultiply(t_color c1, t_color c2);
t_color			color_multiply_1(t_color c1, double n);
t_color			color_add(t_color c1, t_color c2);
t_color			color_substract(t_color c1, t_color c2);
t_color			new_color(int hex);
t_4x4matrix		matrix_multiply(double m1[4][4], double m2[4][4]);
t_vec4			matrix_vec4_multiply(double	m[4][4], t_vec4 p);
int				matrix_4x4_compare(double m1[4][4], double m2[4][4]);
int				matrix_3x3_compare(double m1[3][3], double m2[3][3]);
int				matrix_2x2_compare(double m1[2][2], double m2[2][2]);
void			put4x4matrix(double m[4][4]);
void			put2x2matrix(double m[2][2]);
void			put3x3matrix(double m[3][3]);
t_4x4matrix		matrix_transpose(double m[4][4]);
double			cofactor3x3(double m[3][3], int row, int column);
t_3x3matrix		submatrix4x4(double m[4][4], int row, int column);
t_2x2matrix		submatrix3x3(double m[3][3], int row, int column);
double			determinant2x2(double m[2][2]);
double			determinant3x3(double m[3][3]);
double			cofactor4x4(double m[4][4], int row, int column);
t_4x4matrix		matrix4x4_inverse(double m[4][4]);
t_4x4matrix		translate(double x, double y, double z);
t_4x4matrix		scale(double x, double y, double z);
t_4x4matrix		rotate_x(double r);
t_4x4matrix		rotate_y(double r);
t_4x4matrix		rotate_z(double r);
t_intersection *intersect(t_sphere s, t_ray r);
t_sphere	new_sphere(int id);
t_ray	transform_ray(t_ray r1, double	m[4][4]);
t_intersection	hit(t_intersection *iptr);
t_ray	new_ray(t_vec4 orig, t_vec4 direction);
t_vec4		normal_at(t_sphere s, t_vec4 world_point);
t_material	material();
t_light		point_light(t_vec4 position, t_color intensitivity);
t_vec4			reflect(t_vec4 in, t_vec4 normal);
t_vec4	position(t_ray ray, double t);
t_color		lighting(t_material material, t_light light,t_vec4 point,t_vec4 eyev,t_vec4 normalv);
t_4x4matrix	set_transform(t_sphere s, t_4x4matrix transformation);

void	putcol(t_color c);
# endif
