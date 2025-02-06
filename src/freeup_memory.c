#include "../includes/elements.h"

void	destroy_canvas(t_canvas *canvas)
{
	if (canvas->pixels)
	{
		free(canvas->pixels);
		canvas->pixels = NULL;
	}
}


// Function to free a Matrix
void	free_matrix(t_matrix *matrix)
{
	int	i;

	i = 0;
	if (!matrix->mtrx)
		return ;
	while (i < matrix->size)
	{
		free(matrix->mtrx[i]);
		i++;
	}
	free(matrix->mtrx);
	matrix->mtrx = NULL;
}
