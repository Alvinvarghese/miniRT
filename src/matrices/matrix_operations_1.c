#include "../includes/elements.h"

/* 
	Create a transpose Matrix
*/

t_matrix	transpose_matrix(t_matrix m)
{
	int			i;
	int			j;
	t_matrix	transposed;

	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			transposed.mtrx[i][j] = m.mtrx[j][i];
			j++;
		}
		i++;
	}
	return (transposed);
}

t_tuple	matrix_multiply_tuple(t_matrix m, t_tuple t)
{
	return ((t_tuple){
		m.mtrx[0][0] * t.x + m.mtrx[0][1] * t.y + \
			m.mtrx[0][2] * t.z + m.mtrx[0][3] * t.w,
		m.mtrx[1][0] * t.x + m.mtrx[1][1] * t.y + \
			m.mtrx[1][2] * t.z + m.mtrx[1][3] * t.w,
		m.mtrx[2][0] * t.x + m.mtrx[2][1] * t.y + \
			m.mtrx[2][2] * t.z + m.mtrx[2][3] * t.w,
		m.mtrx[3][0] * t.x + m.mtrx[3][1] * t.y + \
			m.mtrx[3][2] * t.z + m.mtrx[3][3] * t.w
	});
}

/*  // Anotherformat

t_tuple	matrix_multiply_tuple(t_matrix m, t_tuple t)
{
	t_tuple	result;
	double	values[4] = {t.x, t.y, t.z, t.w};
	double	result_values[4] = {0, 0, 0, 0};
	int		i;
	int		j;

	i = 0;
	while (i < m.size)
	{
		j = 0;
		while (j < m.size)
		{
			result_values[i] += m.mtrx[i][j] * values[j];
			j++;
		}
		i++;
	}

	result.x = result_values[0];
	result.y = result_values[1];
	result.z = result_values[2];
	result.w = result_values[3];

	return (result);
} 
*/
