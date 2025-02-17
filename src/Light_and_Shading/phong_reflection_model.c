#include "../includes/elements.h"

t_point_light	create_point_light(t_point position, t_colour intensity)
{
	t_point_light	light;

	light.position = position;
	light.intensity = intensity;

	return (light);
}

/* 
	@@@ LIGHTING @@@

	* The Phong reflection model is a method for simulating how light interacts with surfaces.
	* It describes the way that light reflects off of a surface as a combination of the ambient, diffuse, and specular lighting components.
	* The model was developed by Bui Tuong Phong, who published it in a paper in 1975.
	* The Phong reflection model is a simplification of the rendering equation, which describes the way that light interacts with surfaces in a more general way.
	* The Phong reflection model is widely used in computer graphics because it is relatively simple to compute and gives good results for many types of surfaces.

	* The Phong reflection model is based on the idea that light reflects off of a surface in three different ways:
		- Ambient reflection: This is the light that is scattered in all directions when it hits a surface. It is the same for all points on the surface, regardless of the direction of the light source or the viewer.
		- Diffuse reflection: This is the light that is scattered in all directions when it hits a rough surface. It is proportional to the angle between the direction of the light source and the normal vector to the surface at the point of intersection.
		- Specular reflection: This is the light that is reflected in a single direction when it hits a smooth surface. It is proportional to the angle between the direction of the light source and the direction of the viewer, and it is also affected by the shininess of the surface.		
*/

t_colour	lighting(t_material m, t_point_light l, t_point p, t_vector eyev, 	t_vector normalv)
{
	t_colour	eff_col;
	t_vector	lightv;
	t_colour	ambient;
	t_colour	diffuse;
	t_vector	reflectv;
	t_colour	specular;
	double		factor;
	double		reflect_dot_eye;
	double		light_dot_norm;

	eff_col = multiply_colors(m.colour, l.intensity);
	lightv = normalization(subtraction(l.position, p));
	ambient = multiply_color_by_scalar(eff_col, m.ambient);
	light_dot_norm = dot_product(lightv, normalv);

	if (light_dot_norm < 0)
		return (ambient);
	diffuse = multiply_color_by_scalar(eff_col, m.diffuse * light_dot_norm);
	reflectv = reflect(scalar_multiply(lightv, -1), normalv);
	reflect_dot_eye = dot_product(reflectv, eyev);

	if (reflect_dot_eye <= 0)
		return (add_color(ambient, diffuse));
	factor = pow(reflect_dot_eye, m.shininess);
	specular = multiply_color_by_scalar(l.intensity, m.specular * factor);
	
	return (add_color(add_color(ambient, diffuse), specular));
}
