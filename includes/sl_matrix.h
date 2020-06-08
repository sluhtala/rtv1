#ifndef SL_MATRIX_H
#define SL_MATRIX_H

typedef struct	s_matrix
{
	double	m[4][4];
	struct	s_matrix (*inverse)(struct s_matrix*);	
	struct	s_matrix (*multiply)(struct s_matrix, struct s_matrix);
	t_vec4	(*multiply_vec)(struct s_matrix, t_vec4);
	void	(*identity)(struct s_matrix*);
	struct	s_matrix(*transpose)(struct s_matrix*);
	void	(*putmatrix)(struct s_matrix);
}				t_matrix;

t_matrix		new_matrix();
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

#endif
