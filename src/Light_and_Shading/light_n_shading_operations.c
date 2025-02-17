#include "../includes/elements.h"

/* 
	Computing the normal on a Sphere at the orgin(0,0,0)
*/

t_vector	normal_at(t_point p)
{
	t_vector	normal;

	normal = create_vector(p.x, p.y, p.z);
	return (normalization(normal));
}


/* 
	Computing the normal on a Sphere that has been 
	moved away from the origin.(0,0,0)

	STEPS::
	1. Convert the world point to object space using the inverse 
	of the sphere's transformation matrix:
		object_point=inverse(sphere.transform)×world_point

	2. Compute the object normal difference from sphere center):
			object_normal=object_point−point(0,0,0)

	3. Convert the object normal back to world space:
			world_normal=transpose(inverse(sphere.transform))×object_normal

	4. Ensure the w-component of world_normal is 0.0 
		(since it's a direction vector).
	5. Normalize the world_normal before returning.


*/

t_vector	normal_at(t_sphere *sphere, t_point world_point)
{
	t_matrix	inv_transform;
	t_matrix	inv_transpose;
	t_point		object_point;
	t_vector	object_normal;
	t_vector	world_normal;


	inv_transform = inverse(&sphere->transform);
	object_point = matrix_multiply_tuple(inv_transform, world_point);


	object_normal = subtraction(object_point, create_point(0, 0, 0));


	inv_transpose = transpose(inv_transform);
	world_normal = matrix_multiply_tuple(inv_transpose, object_normal);


	world_normal.w = 0.0;


	return (normalization(world_normal));
}

/* 
		**** Reflecting Vectors ****
*/

t_vector	reflect(t_vector in, t_vector normal)
{
	double		dot_prdt;
	t_vector	scaled_normal;
	t_vector	result;

	dot_prdt = dot_product(in, normal);
	scaled_normal = scalar_multiply(normal, 2 * dot_prdt);
	result = subtraction(in, scaled_normal);
	return (result);
}
