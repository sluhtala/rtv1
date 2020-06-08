#ifndef RTV_1_H
#define RTV_1_H

#include <libft.h>
#include "ft_printf.h"
# include <math.h>
# include "mlx.h"
# include <pthread.h>
# include "sl_colors.h"
# include "sl_vectors.h"
# include "sl_matrix.h"
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
# define HEIGHT 400
# define MAX_INTERSECTION 10
# define SPHERE 1
# define PLANE 2
# define CUBE 3
# define CYLINDER 4
# define CONE 5

typedef struct	s_options
{
	int			simple;
	int			auto_image;
}				t_options;

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


typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}				t_material;

typedef struct	s_camera
{
	int			hsize;
	int			vsize;
	double		field_of_view;
	double		pixel_size;
	double		half_width;
	double		half_height;
	t_matrix	transform;
}				t_camera;

typedef struct	s_light
{
	t_vec4		position;
	t_color		intensitivity;
}				t_light;

typedef struct	s_shape
{
	int			type;
	t_matrix	transform;
	t_matrix	inverse;
	t_material	material;
	t_ray		saved_ray;
	int			id;
	double		minimum;
	double		maximum;
	int			closed;
}				t_shape;

typedef	t_shape	t_sphere;
typedef t_shape t_plane;
typedef t_shape t_cube;
typedef t_shape t_cylinder;
typedef t_shape t_cone;

typedef struct s_intersection
{
	double	t;
	int		count;
	int		null;
	t_shape	*object;
}				t_intersection;

typedef struct	s_xs
{
	t_intersection i[MAX_INTERSECTION];
}				t_xs;

typedef struct	s_computations
{
	double	t;
	int		inside;
	t_shape	*object;
	t_vec4	point;
	t_vec4	normalv;
	t_vec4	eyev;
	t_vec4	over_point;
}				t_computations;

typedef struct	s_world
{
	int		objectamount;
	int		lightamount;
	t_shape	*shapes;
	t_light	*lights;
}				t_world;

typedef struct	s_lighting
{
	t_material *material;
	t_light		light;
	t_vec4		point;
	t_vec4		eyev;
	t_vec4		normalv;
	int			in_shadow;	
	t_color	effective_color;
	t_vec4	lightv;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_vec4	reflectv;
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;
}				t_lighting;

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
t_vec4			vector(double x, double y, double z);
t_vec4			point(double x, double y, double z);
void			init_rt(t_data *data);
void			image_to_window(t_data *data);
void			set_options(t_data *data, int ac, char **av);
void			update_buffer(t_data *data);
void			img_to_ppm(t_image img, char *file_name, t_data *data);

t_matrix		translate(double x, double y, double z);
t_matrix		scale(double x, double y, double z);
t_matrix		rotate_x(double r);
t_matrix		rotate_y(double r);
t_matrix		rotate_z(double r);

t_ray			new_ray(t_vec4 orig, t_vec4 direction);
t_ray			transform_ray(t_ray r1, t_matrix	*m);
t_vec4			position(t_ray ray, double t);
t_vec4			reflect(t_vec4 in, t_vec4 normal);
void			set_transform(t_shape *shape, t_matrix transformation);
t_intersection	*hit(t_xs *iptr);
t_xs 			intersect(t_shape *shape, t_ray ray);
t_intersection	new_intersection(t_shape *object, double t, int count);
t_vec4			normal_at(t_shape *shape, t_vec4 point);
void			sort_intersect(t_intersection *i, int count);
t_material		new_material();
t_light			point_light(t_vec4 position, t_color intensitivity);

t_color			lighting(t_lighting *l);

t_sphere		new_sphere(int id);
t_xs 			intersect_sphere(t_sphere *s, t_ray r);
t_vec4			sphere_normal_at(t_vec4 pnt);
void			delete_sphere(t_sphere s);



t_camera 	new_camera(int hsize, int vsize, double fov);
t_matrix 	view_transform(t_vec4 from,t_vec4 to,t_vec4 up);
int	 		sphere_test(t_data *data);
void		set_identity_matrix(t_matrix *m);
t_xs 		xs_init();
t_xs		intersect_world(t_world *w, t_ray r);
t_world		default_world();
t_color		**render(t_camera camera, t_world *world);
t_color		color_at(t_world *w, t_ray r);

t_vec4		plane_normal_at();
t_xs 		intersect_plane(t_plane *p, t_ray r);
t_plane 	new_plane(int id);

t_vec4		cube_normal_at(t_vec4 point);
t_xs		intersect_cube(t_cube *c, t_ray r);
t_cube 		new_cube(int id);

t_cylinder 	new_cylinder(int id);
t_vec4		cylinder_normal_at(t_shape* shape, t_vec4 point);
t_xs		intersect_cylinder(t_cylinder *c, t_ray r);

t_xs		intersect_cone(t_cone *c, t_ray r);
t_vec4		cone_normal_at(t_shape* shape, t_vec4 point);
t_cube 		new_cone(int id);

void		all_scene(t_world *world, t_camera *cam, t_data *data);
t_world		new_world(int object_amount, int light_amount);
void		default_scene(t_world *world, t_camera *cam, t_data *data);

# endif
