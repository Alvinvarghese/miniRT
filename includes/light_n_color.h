/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_n_color.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:14:12 by avarghes          #+#    #+#             */
/*   Updated: 2025/02/18 11:46:23 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_N_COLOR_H
# define LIGHT_N_COLOR_H

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

typedef struct s_point_light
{
	t_point		position;
	t_colour	intensity;
}				t_point_light;

typedef struct material
{
	t_colour	colour;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}				t_material;


	/* ****	COLOR_OPN_CANVAS.C **** */
t_canvas	create_canvas(int width, int height);
void		write_pixel(t_canvas *canvas, int x, int y, t_colour color);

	/* ****	COLOR_OPN_CANVAS1.C **** */
t_colour	create_color(float r, float g, float b);
t_colour	add_color(t_colour c1, t_colour c2);
t_colour	subtract_color(t_colour c1, t_colour c2);
t_colour	multiply_colors(t_colour c1, t_colour c2);
t_colour	multiply_color_by_scalar(t_colour c, float scalar);

	/* ****	LIGHT_N_SHADING_OPERATION.C **** */
t_vector	normal_at(t_point p);
t_vector	normal_at(t_sphere *sphere, t_point world_point);
t_vector	reflect(t_vector in, t_vector normal);

	/* ****	PHONG_REFLECTION_MODEL.C **** */

#endif