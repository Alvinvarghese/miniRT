
#include "../includes/minirt.h"
#include <stdio.h>
#include <mlx.h>
#include "../includes/elements.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	key_hook(int keycode, void *param)
{
	if (keycode == 65307) // 65307 is the keycode for Esc
		exit(0);
	(void)param;
	return (0);
}

int main(int argc, char **argv)
{
    void *mlx;
    void *win;
    t_canvas canvas;
    t_colour color;
    t_image img;

    (void)argc;
    (void)argv;

    mlx = mlx_init();
    if (mlx == NULL)
    {
        fprintf(stderr, "Error initializing MLX\n");
        return (1);
    }
    win = mlx_new_window(mlx, 800, 600, "miniRT");
    if (win == NULL)
    {
        fprintf(stderr, "Error creating window\n");
        mlx_destroy_display(mlx);
        free(mlx);
        return (1);
    }

    // Create a canvas and draw something on it
    canvas = create_canvas(800, 600);
    /* color.r = 1.0f;
    color.g = 0.0f;
    color.b = 0.0f; */
    color = create_colour(1.0f, 0.0f, 0.0f);
    write_pixel(&canvas, 400, 300, color);

    // Convert the canvas to an image
    img.img = mlx_new_image(mlx, canvas.width, canvas.height);
	img.data = mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
	int y = 0;
	while (y < canvas.height)
	{
		int x = 0;
		while (x < canvas.width)
		{
			int index = (y * canvas.width + x) * 4;
			img.data[index] = (char)(canvas.pixels[y * canvas.width + x].b * 255);
			img.data[index + 1] = (char)(canvas.pixels[y * canvas.width + x].g * 255);
			img.data[index + 2] = (char)(canvas.pixels[y * canvas.width + x].r * 255);
			img.data[index + 3] = 0;
			x++;
		}
		y++;
	}

    // Display the image on the window
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);

    mlx_hook(win, 17, 0, close_window, NULL); // 17 is the event code for the close button
    mlx_key_hook(win, key_hook, NULL); // Register key hook

    mlx_loop(mlx);
    mlx_destroy_image(mlx, img.img);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
    free(mlx);
    free(canvas.pixels);
    return (0);
}
