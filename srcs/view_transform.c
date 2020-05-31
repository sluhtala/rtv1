#include "rtv_1.h"

static t_matrix	set_matrix(t_vec4 l, t_vec4 t, t_vec4 f)
{
	t_matrix m;

	m = new_matrix();
	m.m[0][0] = l.x;
	m.m[0][1] = l.y;
	m.m[0][2] = l.z;
	m.m[0][3] = 0;
	m.m[1][0] = t.x;
	m.m[1][1] = t.y;
	m.m[1][2] = t.z;
	m.m[1][3] = 0;
	m.m[2][0] = -f.x;
	m.m[2][1] = -f.y;
	m.m[2][2] = -f.z;
	m.m[2][3] = 0;
	m.m[3][0] = 0;
	m.m[3][1] = 0;
	m.m[3][2] = 0;
	m.m[3][3] = 1;
	return (m);
}

t_matrix view_transform(t_vec4 from,t_vec4 to,t_vec4 up)
{
	t_matrix m;
	t_matrix temp2;
	t_vec4 forward;
	t_vec4 upn;
	t_vec4 left;
	t_vec4 true_up;
	t_matrix temp;

	forward = vec4_normalize(vec4_substract(to, from));
	upn = vec4_normalize(up);
	left = vec4_cros(forward, upn);
	true_up = vec4_cros(left, forward);
	m = set_matrix(left, true_up, forward);
	temp = translate(-from.x, -from.y, -from.z);
	temp2 = matrix_multiply(m, temp);
	return (temp2);	
}
