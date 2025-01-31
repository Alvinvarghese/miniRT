#include "elements.h"
// This function frees the memory allocated for the canvas pixels
void	destroy_canvas(t_canvas *canvas)
{
	if (canvas->pixels)
	{
		free(canvas->pixels);
		canvas->pixels = NULL;
	}
}
