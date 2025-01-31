#include <math.h>
#include <stdlib.h>

/*
Structure to represent Tuples, Points & Vectors 
 */
typedef struct s_tuples
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_tuple;

/*
Structure to represent Colour spectrum 
 */
typedef struct s_colours
{
	float		r;
	float		g;
	float		b;
}				t_colour;

/* 
	A canvas is just a rectangular grid of pixels

	*pixels --> Array storing pixel colors
 */
typedef struct s_canvas
{
	int			width;
	int			height;
	t_colour	*pixels;
}				t_canvas;

/* 

 */


t_tuple	addition(t_tuple, t_tuple);
t_tuple	subtraction(t_tuple, t_tuple);