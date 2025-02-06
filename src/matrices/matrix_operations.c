#include "elements.h"

/* 

*****   CREATE A MATRIX ******

//	Function to allocate memory for a matrix
	By giving the size this fn will create a size x size matrix.
	eg: size = 3 ==> then a matrix of 3 x 3

 */

t_matrix	create_matrix(int size)
{
	t_matrix	matrix;
	int			i;
	int			j;

	i = 0;
	matrix.size = size;
	matrix.mtrx = (double **)malloc(size * sizeof(double *));
	while (i < size)
	{
		matrix.mtrx[i] = (double *)malloc(size * sizeof(double));
		/* if (!matrix.mtrx[i])
		{
			j = 0;
			while (j < i)
			{
				free(matrix.mtrx[j]);
				j++;
			}
			free(matrix.mtrx);
			matrix.mtrx = NULL;
			return (matrix);
		} */
		i++;
	}
	return (matrix);
}

/* 

*****  MATRIX MULTIPLICATION   ******
	Multiplying matrix of equal size 
	a = 3x3, b = 3x3
	c = axb (3x3)
 */
t_matrix	matrix_multiplication(t_matrix *a, t_matrix *b, int size)
{
	int			row;
	int			col;
	int			idx;
	t_matrix	m;

	row = 0;
	col = 0;
	while (row < size)
	{
		while (col < size)
		{
			m.mtrx[row][col] = 0;
			idx = 0;
			while (idx < size)
			{
				m.mtrx[row][col] += a->mtrx[row][idx] * b->mtrx[idx][col];
				idx++;
			}
			col++;
		}
		row++;
	}
	return (m);
}


/* 

	*****  COFACTOR ******
	// Create a submatrix by excluding the given row and column
	// Get the submatrix
	// Compute the determinant of the submatrix
	// Apply the cofactor sign based on the row and column position
	// The cofactor is the sign multiplied by the determinant of the submatrix
	// Free the submatrix memory
 */

double	cofactor(t_matrix *matrix, int row, int col)
{
	t_matrix	submatrix;
	double		cofactor_value;
	double		sign;
	double		det;

	submatrix = create_matrix(matrix->size - 1);
	get_submatrix(matrix, &submatrix, row, col);
	det = determinant(&submatrix);

	if ((row + col) % 2 == 0)
		sign = 1;
	else
		sign = -1;
	cofactor_value = sign * det;

	free_matrix(&submatrix);

	return (cofactor_value);
}

/* 

	*****  INVERSE ******
	// Function to compute the inverse of a matrix
    // If determinant is 0, the matrix is not invertible 
		then return a matrix of size 0
	// else, allocate space for the inverse matrix
	// Compute the cofactor of (row, col)
	// Store transposed element: M2[col][row] = c / det
 */

t_matrix inverse(t_matrix *M)
{
    double		det;
	 double		c;
	int			size;
	int			row;
	int			col;
	t_matrix	M2;

    det = determinant(M);

    if (det == 0)
    {
        printf("Matrix is not invertible.\n");
        return (create_matrix(0));
    }

    size = M->size;
    M2 = create_matrix(size);

    row = 0;
    while (row < size)
    {
        col = 0;
        while (col < size)
        {
            c = cofactor(M, row, col);

            M2.mtrx[col][row] = c / det;

            col++;
        }
        row++;
    }

    return (M2);
}