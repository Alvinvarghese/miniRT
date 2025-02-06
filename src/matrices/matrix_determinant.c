#include "elements.h"

/* 
	*****  GET_SUBMATRIX ******
	
	// Function to get a submatrix (minor)

	A submatrix is what is left when you delete a 
	single row and column from a matrix.

	fn :: sub_matrix(matrix, row, column)
			row & column ==> which has to be removed.

	if (i == row) continue; // Skip the selected row
	if (i == col) continue; // Skip the selected col
 */

void	get_submatrix(t_matrix *src, t_matrix *dest, int row, int col)
{
	int	r;
	int	c;
	int	i;
	int	j;

	r = 0;
	i = 0;
	while (i < src->size)
	{
		if (i == row)
		{
			i++;
			continue ;
		}
		c = 0;
		j = 0;
		while (j < src->size)
		{
			if (j == col)
			{
				j++;
				continue ;
			}
			dest->mtrx[r][c] = src->mtrx[i][j];
			c++;
			j++;
		}
		i++;
		r++;
	}
}

/* 

	*****  BASE_CASE_DETERMINANT ******

	// Base case: 1×1 matrix determinant
	// Base case: 2×2 determinant

 */


double	base_case_determinant(t_matrix *matrix)
{
	if (matrix->size == 1)
		return (matrix->mtrx[0][0]); 
	if (matrix->size == 2) 
		return ((matrix->mtrx[0][0] * matrix->mtrx[1][1]) - \
				(matrix->mtrx[0][1] * matrix->mtrx[1][0]));
	return (0);
}

/* 
	*****  DETERMINANT ******

	// Function to calculate the determinant of a matrix
	// Compute determinant recursively using Laplace expansion
 */

double	determinant(t_matrix *matrix)
{
	double		det;
	double		minor_det;
	int			col;
	t_matrix	submatrix;

	col = 0;
	det = base_case_determinant(matrix);
	if (matrix->size <= 2)
		return (det);
	det = 0;
	while (col < matrix->size)
	{
		submatrix = create_matrix(matrix->size - 1);
		get_submatrix(matrix, &submatrix, 0, col);
		minor_det = determinant(&submatrix);
		if (col % 2 == 0)
			det += matrix->mtrx[0][col] * minor_det;
		else
			det -= matrix->mtrx[0][col] * minor_det;
		free_matrix(&submatrix);
		col++;
	}
	return (det);
}
