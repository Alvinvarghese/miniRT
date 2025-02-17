#include "../includes/elements.h"

/* 

	***** SHEARING *****
	A shearing (or skew) transformation has the effect of 
	making straight lines slanted.

	the x component changes in proportion to y and z 
			==>		x_y , x_z, 
	the y component changes in proportion to x and z,
			==>		y_x , y_z 
	the z component changes in proportion to x and y.
			==>		z_x , z_y
	
	shearing(x_y, x_z, y_x, y_z, z_x, z_y)  ==>

		1		x_y		x_z		0
		y_x		1		y_z		0
		z_x		z_y		1		0
		0		0		0		1	

 */

t_matrix	shearing(double x_y, double x_z,
					double y_x, double y_z,
					double z_x, double z_y)
{
	t_matrix	shear;

	shear = create_identity_matrix(4);
	shear.mtrx[0][1] = x_y;
	shear.mtrx[0][2] = x_z;
	shear.mtrx[1][0] = y_x;
	shear.mtrx[1][2] = y_z;
	shear.mtrx[2][0] = z_x;
	shear.mtrx[2][1] = z_y;

	return (shear);
}


/* 

	// if need to reduce the number of parameters::

			Method 1

	t_matrix shearing(double shear_factors[6]) 
	{
    t_matrix shear = create_identity_matrix(4);

    shear.mtrx[0][1] = shear_factors[0]; // x_y
    shear.mtrx[0][2] = shear_factors[1]; // x_z
    shear.mtrx[1][0] = shear_factors[2]; // y_x
    shear.mtrx[1][2] = shear_factors[3]; // y_z
    shear.mtrx[2][0] = shear_factors[4]; // z_x
    shear.mtrx[2][1] = shear_factors[5]; // z_y

    return (shear);
}

	passing by :: 
		double factors[6] = { x_y, x_z, y_x, y_z, z_x, z_y };
		t_matrix shear_mtrx = shearing(factors);


		Method 2

	typedef struct 
	{
    double x_y, x_z;
    double y_x, y_z;
    double z_x, z_y;
	} t_shear;

t_matrix shearing(t_shear shear_factors) {
    t_matrix shear = create_identity_matrix(4);

    shear.mtrx[0][1] = shear_factors.x_y;
    shear.mtrx[0][2] = shear_factors.x_z;
    shear.mtrx[1][0] = shear_factors.y_x;
    shear.mtrx[1][2] = shear_factors.y_z;
    shear.mtrx[2][0] = shear_factors.z_x;
    shear.mtrx[2][1] = shear_factors.z_y;

    return shear;
}

	passing by::
		t_shear factors = { x_y, x_z, y_x, y_z, z_x, z_y };
		t_matrix shear_mtrx = shearing(factors);

 */