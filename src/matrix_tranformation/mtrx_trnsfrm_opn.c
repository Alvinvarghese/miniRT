#include "../includes/elements.h"

t_matrix	create_identity_matrix(int size)
{
	t_matrix	identity_mtrx;
	int			i;

	i = 0;
	identity_mtrx = create_matrix(size);
	while (i < size)
	{
		identity_mtrx.mtrx[i][i] = 1.0;
		i++;
	}
	return (identity_mtrx);
}

/* 
	**** Translation Matrix ****
	Translation Matrix is an identity matrix 
	with x,y,z at t03, t13, and t23

 */

t_matrix	create_translation_mtrx(float x, float y, float z)
{
	t_matrix	trnsltn_mtrx;

	trnsltn_mtrx = create_identity_matrix(4);
	trnsltn_mtrx.mtrx[0][3] = x;
	trnsltn_mtrx.mtrx[1][3] = y;
	trnsltn_mtrx.mtrx[2][3] = z;
	return (trnsltn_mtrx);
}


/* 

	***** SCALING *****
	Translation moves a point by adding to it,
	Scaling moves it by multiplication.


	NOTE::	Reflection is essentially the same thing 
			as scaling by a negative value.
 */

t_matrix	create_scaling_mtrx(float x, float y, float z)
{
	t_matrix	scaling_mtrx;

	scaling_mtrx = create_identity_matrix(4);
	scaling_mtrx.mtrx[0][0] = x;
	scaling_mtrx.mtrx[1][1] = y;
	scaling_mtrx.mtrx[2][2] = z;
	return (scaling_mtrx);
}

/* 

REMANING ::
			CHANING TRANSFORMATION

 */
