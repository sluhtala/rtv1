#include <stdio.h>

typedef struct s_mat4 
{
	double m[4][4];

}		t_mat4;

typedef double mat[4][4];

#define matrix "t_mat4.m"

typedef struct s_matrix4
{
	double m[4][4];
	func identity;
	func inverse;
	func descriminant;
	func transpose;
	



}			t_matrix4;

int main()
{
	mat m;

	m[0][0] = 3;
	printf("%f\n", m[0][0]);
}
