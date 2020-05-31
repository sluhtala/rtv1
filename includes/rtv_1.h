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
# define EPSILON 0.000001
# define WIDTH 600
# define HEIGHT 600

typedef struct	s_options
{
	int			simple;
	int			auto_image;
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

typedef struct	s_matrix
{
	double m[4][4];
	struct s_matrix (*inverse)(struct s_matrix*);	
	struct s_matrix (*multiply)(struct s_matrix, struct s_matrix);
	t_vec4 (*multiply_vec)(struct s_matrix, t_vec4);
	void(*identity)(struct s_matrix*);
	struct s_matrix(*transpose)(struct s_matrix*);
	void(*putmatrix)(struct s_matrix);
}				t_matrix;

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
	t_material	material;
	t_matrix transform;
}				t_sphere;

typedef struct s_intersection
{
	double t;
	int count;
	t_sphere object;
}				t_intersection;

typedef struct	s_world
{
	int objectamount;
	int lightamount;
	t_sphere *spheres;
	t_light *lights;
}				t_world;

typedef struct s_computations
{
	double t;
	int inside;
	t_sphere object;
	t_vec4 point;
	t_vec4 normalv;
	t_vec4 eyev;
	t_vec4 over_point;
}				t_computations;

typedef struct	s_camera
{
	int hsize;
	int vsize;
	double field_of_view;
	double pixel_size;
	double half_width;
	double half_height;
	t_matrix transform;
}				t_camera;

typedef struct	s_data
{
	int			width;
	int			height;
	t_mlx		mlx;
	t_image		img;
	t_options	opt;
	t_camera	camera;
	t_world		world;
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

t_matrix		matrix_multiply(t_matrix m1, t_matrix m2);
t_vec4			matrix_vec4_multiply(t_matrix m, t_vec4 p);
int				matrix_4x4_compare(t_matrix *m1, t_matrix *m2);
int				matrix_3x3_compare(t_matrix *m1, t_matrix *m2);
int				matrix_2x2_compare(t_matrix *m1, t_matrix *m2);
void			put4x4matrix(t_matrix m);
void			put2x2matrix(t_matrix m);
void			put3x3matrix(t_matrix m);
t_matrix		matrix_transpose(t_matrix *m);
double			cofactor3x3(t_matrix *m, int row, int column);
t_matrix		submatrix4x4(t_matrix *m, int row, int column);
t_matrix		submatrix3x3(t_matrix *m, int row, int column);
double			determinant2x2(t_matrix *m);
double			determinant3x3(t_matrix *m);
double			cofactor4x4(t_matrix *m, int row, int column);
t_matrix		matrix4x4_inverse(t_matrix *m);
t_matrix		translate(double x, double y, double z);
t_matrix		scale(double x, double y, double z);
t_matrix		rotate_x(double r);
t_matrix		rotate_y(double r);
t_matrix		rotate_z(double r);

t_sphere	new_sphere(int id);
t_ray	transform_ray(t_ray r1, t_matrix	*m);
t_intersection	*hit(t_intersection *iptr);
t_intersection *intersect(t_sphere s, t_ray r);
t_ray	new_ray(t_vec4 orig, t_vec4 direction);
t_vec4		normal_at(t_sphere *s, t_vec4 world_point);
t_material	new_material();
t_light		point_light(t_vec4 position, t_color intensitivity);
t_vec4			reflect(t_vec4 in, t_vec4 normal);
t_vec4	position(t_ray ray, double t);
t_color		lighting(t_material material, t_light light,t_vec4 point,t_vec4 eyev,t_vec4 normalv, int in_shadow);
void	set_transform(t_sphere *s, t_matrix transformation);

void	delete_sphere(t_sphere s);

t_matrix	new_matrix();
//void		delete_matrix(t_matrix m);

void	putcol(t_color c);


void	init_rt(t_data *data);
void	image_to_window(t_data *data);
void	set_options(t_data *data, int ac, char **av);
void	update_buffer(t_image img, t_data *data);
t_vec4	vector(double x, double y, double z);
t_vec4	point(double x, double y, double z);
void	img_to_ppm(t_image img, char *file_name, t_data *data);

int	 sphere_test(t_data *data);
void	set_identity_matrix(t_matrix *m);
t_intersection *intersect_world(t_world *w, t_ray r);
t_world		default_world();
t_matrix view_transform(t_vec4 from,t_vec4 to,t_vec4 up);
t_color		**render(t_camera camera, t_world *world);
t_camera new_camera(int hsize, int vsize, double fov);
t_color		color_at(t_world *w, t_ray r);



# endif
