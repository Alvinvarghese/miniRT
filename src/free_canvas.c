#include "elements.h"

void	destroy_canvas(t_canvas *canvas)
{
	if (canvas->pixels)
	{
		free(canvas->pixels);
		canvas->pixels = NULL;
	}
}
