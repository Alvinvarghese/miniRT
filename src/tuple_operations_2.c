#include "../includes/elements.h"

/* 
	***MAGNITUDE****
The distance represented by a vector is
called its magnitude, or length. It’s how far you would travel in a straight line
if you were to walk from one end of the vector to the other.

*** magnitude(v) = sqrt(vx *vx + vy*vy + vz*vz + vw*vw) ***

Vectors with magnitudes of 1 are called a unit vectors,
 */

double	magnitude(t_tuple p)
{
	double	magnitude_v;

	magnitude_v = sqrt (p.x * p.x + p.y * p.y + p.z * p.z + p.w * p.w);
	return (magnitude_v);
}


/*   !!!!!!!! NEED TO CONFIRM !!!!


	**** NORMALIZATION ****
Normalization is the process of taking an arbitrary vector and converting it
into a unit vector.

normalize a tuple by dividing each of its components by its magnitude

 */

t_tuple	normalization(t_tuple p)
{
	double	v;

	v = magnitude(p);
	p.x = p.x / v;
	p.y = p.y / v;
	p.z = p.z / v;
	return (p);
}


/* 
	**** DOT PRODUCT ****

	*the dot product is computed as the sum of the
	products of the corresponding components of each vector.
	
	*The dot product takes two vectors and returns a scalar value

 */

double	dot_product(t_tuple a, t_tuple b)
{
	t_tuple	p;

	p.x = a.x * b.x;
	p.y = a.y * b.y;
	p.z = a.z * b.z;
	p.w = a.w * b.w;
	return (p.x + p.y + p.z);
}

/* 

	**** CROSS PRODUCT ****

	The cross product is another vector operation, but unlike the
	dot product, it returns another vector instead of a scalar.

	
 */

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple	v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	v.w = 0;
	return (v);
}
