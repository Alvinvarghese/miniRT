#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#include "tuples.h"
#include "matrix.h"
#include "light_n_color.h"
#include "free.h"




/*
	Structure to represent an image
 */
typedef struct s_image
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef t_tuple	t_point;
typedef t_tuple	t_vector;

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;


typedef struct s_sphere
{
	t_point		center;
	double		radius;
	t_material	material;
}				t_sphere;


/*			rendering		*/
int				close_window(void *param);
int				key_hook(int keycode, void *param);
void			render_canvas_to_image(t_canvas *canvas, t_image *img,
					void *mlx);
void			initialize_and_render(void *mlx, void *win);

void			*initialize_mlx(void);
void			*create_window(void *mlx, int width, int height, char *title);
void			setup_mlx_hooks_and_loop(void *mlx, void *win);


/*			ray				*/
t_point			create_point(double x, double y, double z);
t_vector		create_vector(double x, double y, double z);
t_point			add_vector_to_point(t_point p, t_vector v);
t_vector		multiple_vector(t_vector v, double scalar);
t_point			position(t_ray ray, double t);
double			dot_product(t_vector a, t_vector b);
t_vector		subtract(t_point a, t_point b);
t_vector		normalize(t_vector v);

/*			rendering		*/
int				close_window(void *param);
int				key_hook(int keycode, void *param);
void			render_canvas_to_image(t_canvas *canvas, t_image *img,
					void *mlx);
void			initialize_and_render(void *mlx, void *win);
void			*initialize_mlx(void);
void			*create_window(void *mlx, int width, int height, char *title);
void			setup_mlx_hooks_and_loop(void *mlx, void *win);