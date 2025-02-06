#include "../includes/elements.h"

/* 
	**** CREATE COLOUR ****
 */

t_colour	create_color(float r, float g, float b)
{
	t_colour	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}


t_colour	add_color(t_colour c1, t_colour c2)
{
	t_colour	c;

	c.r = c1.r + c2.r;
	c.g = c1.g + c2.g;
	c.b = c1.b + c2.b;
	return (c);
}

t_colour	subtract_color(t_colour c1, t_colour c2)
{
	t_colour	c;

	c.r = c1.r - c2.r;
	c.g = c1.g - c2.g;
	c.b = c1.b - c2.b;
	return (c);
}

/* 
	**** MULTIPLY COLOURS ****
	It’s technically called the
	Hadamard product (or Schur product),
 */

t_colour	multiply_colors(t_colour c1, t_colour c2)
{
	t_colour	c;

	c.r = c1.r * c2.r;
	c.g = c1.g * c2.g;
	c.b = c1.b * c2.b;
	return (c);
}

t_colour	multiply_color_by_scalar(t_colour c, float scalar)
{
	c.r = c.r * scalar;
	c.g = c.g * scalar;
	c.b = c.b * scalar;
	return (c);
}
