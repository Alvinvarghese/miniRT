#include <math.h>

typedef struct s_tuples
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_tuple;

t_tuple	addition(t_tuple, t_tuple);
t_tuple	subtraction(t_tuple, t_tuple);