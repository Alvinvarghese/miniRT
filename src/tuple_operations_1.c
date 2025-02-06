#include "../includes/elements.h"

/* 
	@@@ For Tuple Addition @@@

a point (w = 1)
a vector (w = 0)

a point + a vector = a point
a vector + a vector = a vector

a point + a point  != apoint or a vector!!!
 */

t_tuple	addition(t_tuple p1, t_tuple p2)
{
	t_tuple	p;

	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	p.z = p1.z + p2.y;
	p.w = p1.w + p2.w;
	return (p);
}

/* 
	@@@ For Tuple Subtraction @@@

a point (w = 1)
a vector (w = 0)

a point - a vector = a vector
a vector - a vector = a vector

a vector - a point  != (-w component)a point or a vector!!!
 */

t_tuple	subtraction(t_tuple p1, t_tuple p2)
{
	t_tuple	p;

	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	p.z = p1.z - p2.y;
	p.w = p1.w - p2.w;
	return (p);
}

t_tuple	negation(t_tuple a)
{
	a.x *= -1;
	a.y *= -1;
	a.z *= -1;
	a.w *= -1;
	return (a);
}

t_tuple	multiplication(t_tuple a, double scalar)
{
	a.x *= scalar;
	a.y *= scalar;
	a.z *= scalar;
	a.w *= scalar;
	return (a);
}

t_tuple	divide_by_two(t_tuple a)
{
	a.x /= 2.0;
	a.y /= 2.0;
	a.z /= 2.0;
	a.w /= 2.0;
	return (a);
}

