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
    Structure to represent an image
 */
typedef struct s_image
{
    void *img;
    char *data;
    int bpp;
    int size_line;
    int endian;
}				t_image;
/* 

 */

typedef struct s_matrix
{
	double	**mtrx;
	int		size;
}				t_matrix;

typedef	t_tuple t_point;
typedef	t_tuple t_vector;
typedef struct
{
	t_point origin;
	t_vector direction;
} ray;

t_tuple	addition(t_tuple, t_tuple);
t_tuple	subtraction(t_tuple, t_tuple);
t_canvas create_canvas(int width, int height);
void write_pixel(t_canvas *canvas, int x, int y, t_colour color);
