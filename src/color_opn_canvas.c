#include "../includes/elements.h"

/* 
	Intializing the canvas to black color(0,0,0)

	while-loop is doing the intialization to black
 */

t_canvas	create_canvas(int width, int height)
{
	int			i;
	t_canvas	canvas;

	i = 0;
	canvas.width = width;
	canvas.height = height;
	canvas.pixels = (t_colour *)malloc(width * height * sizeof(t_colour));
	if (!canvas.pixels)
		return (canvas);
	while (i < width * height)
	{
		canvas.pixels[i].r = 0.0f;
		canvas.pixels[i].g = 0.0f;
		canvas.pixels[i].b = 0.0f;
		i++;
	}
	return (canvas);
}

// index = y * canvas->width + x; ==> converting (x,y) to 1D index
void	write_pixel(t_canvas *canvas, int x, int y, t_colour color)
{
	int	index;

	if (x < 0 || x >= canvas->width || \
		y < 0 || y >= canvas->height)
		return ;
	index = y * canvas->width + x;
	canvas->pixels[index] = color;
}
