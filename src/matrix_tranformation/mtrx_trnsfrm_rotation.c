#include "../includes/elements.h"


/* 
	***** ROTATION *****

	The rotation will appear to be clockwise around the corresponding 
	axis when viewed along that axis, toward the negative end.

	3 fns ==> 	rotation_x(radians)
				rotation_y(radians)
				rotation_z(radians)
 */

/* 	
		Rotation Around the X Axis
	  		***** ROTATION_X *****

	The transformation matrix 
	for rotating r radians around the x axis is::

		Rx​(θ)=  ​1		   0	  0		 0
				​0		cosθ	sinθ	0
				​0		−sinθ	cosθ	0
				​0		  0		  0		1​

 */

t_matrix	rotation_x(double radians)
{
	t_matrix	rotate_x;

	rotate_x = create_identity_matrix(4);
	rotate_x.mtrx[1][1] = cos(radians);
	rotate_x.mtrx[1][2] = -sin(radians);
	rotate_x.mtrx[2][1] = sin(radians);
	rotate_x.mtrx[2][2] = cos(radians);

	return (rotate_x);
}

/* 
		Rotation Around the Y Axis
	  		***** ROTATION_Y *****

	The transformation matrix 
	for rotating r radians around the x axis is::

		Rx​(θ)=  ​cosθ	   0	 sinθ	  0
				​0		  1		  0		 0
				−sinθ	 0		cosθ	0
				​0		  0		  0		 1​

 */

t_matrix	rotation_y(double radians)
{
	t_matrix	rotate_y;

	rotate_y = create_identity_matrix(4);
	rotate_y.mtrx[0][0] = cos(radians);
	rotate_y.mtrx[0][2] = sin(radians);
	rotate_y.mtrx[2][0] = -sin(radians);
	rotate_y.mtrx[2][2] = cos(radians);

	return (rotate_y);
}

/* 
		Rotation Around the Y Axis
	  		***** ROTATION_Y *****

	The transformation matrix 
	for rotating r radians around the x axis is::

		Rx​(θ)=	 ​cosθ	  −sinθ	  0		0
				sinθ	cosθ	0	  0
				0		0		0	  0
				​0		 0		 0	   1​

 */

t_matrix	rotation_z(double radians)
{
	t_matrix	rotate_z;

	rotate_z = create_identity_matrix(4);
	rotate_z.mtrx[0][0] = cos(radians);
	rotate_z.mtrx[0][1] = -sin(radians);
	rotate_z.mtrx[1][0] = sin(radians);
	rotate_z.mtrx[1][1] = cos(radians);

	return (rotate_z);
}
