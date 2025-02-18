/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:36:12 by shkaruna          #+#    #+#             */
/*   Updated: 2025/02/18 10:25:38 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void render_canvas_to_image(t_canvas *canvas, t_image *img, void *mlx)
{
    img->img = mlx_new_image(mlx, canvas->width, canvas->height);
    img->data = mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
    int y = 0;
    while (y < canvas->height)
    {
        int x = 0;
        while (x < canvas->width)
        {
            int index = (y * canvas->width + x) * 4;
            img->data[index] = (char)(canvas->pixels[y * canvas->width + x].b * 255);
            img->data[index + 1] = (char)(canvas->pixels[y * canvas->width + x].g * 255);
            img->data[index + 2] = (char)(canvas->pixels[y * canvas->width + x].r * 255);
            img->data[index + 3] = 0;
            x++;
        }
        y++;
    }
}

void initialize_and_render(void *mlx, void *win)
{
    t_canvas canvas;
    t_colour color;
    t_image img;

    // Create a canvas and draw something on it
    canvas = create_canvas(800, 600);
    color = create_color(1.0f, 0.0f, 0.0f);
    write_pixel(&canvas, 400, 300, color);

    // Convert the canvas to an image and display it
    render_canvas_to_image(&canvas, &img, mlx);
    mlx_put_image_to_window(mlx, win, img.img, 0, 0);

    // Clean up
    free(canvas.pixels);
    mlx_destroy_image(mlx, img.img);
}
