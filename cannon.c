#include "rtv_1.h"
#include <math.h>
#include <stdio.h>

typedef struct s_env
{
	t_vec3	gravity;
	t_vec3	wind;
}				t_env;

typedef struct	s_proj
{
	t_vec3	position;
	t_vec3	velocity;
}				t_proj;

t_proj	tick(t_env env, t_proj proj)
{
	t_proj r;
	double m;
	double b;

	r.position = vec3_add(proj.position, proj.velocity);
	r.velocity = vec3_add(vec3_add(proj.velocity, env.gravity), env.wind);
//	if (r.position.y < 0)
//	{
//		m = (proj.position.y - r.position.y) / (proj.position.x - r.position.x);
//		b = r.position.y / (r.position.x * m);
//		r.position.y = 0;
//		r.position.x = -b / m;
//	}
	return (r);
}

void	cannon(t_data *data)
{
	t_proj p;
	t_env e;
	t_color col;

	col = new_color(WHITE);
	p.position = new_vec3(0,1,0);
	p.velocity = vec3_normalize(new_vec3(.5, 1, 0));
	p.velocity = vec3_multiply(new_vec3(10,10,10),p.velocity);
	e.gravity = new_vec3(0, -.2, 0);
	e.wind = new_vec3(-.02, .04, 0);
	int i;
	i = p.position.x;
	while (p.position.y > 0)
	{
		if (p.position.y < HEIGHT && p.position.y >= 0 && i < WIDTH && i >= 0)
			data->img.pixels[HEIGHT - (int)p.position.y][i] = col;
		//printf("%.2f\n", p.position.x);
		p = tick(e, p);
		if (i >= WIDTH)
			break;
		i = p.position.x;
	}
	return;
}
