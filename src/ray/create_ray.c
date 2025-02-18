/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:24:27 by shkaruna          #+#    #+#             */
/*   Updated: 2025/02/18 10:38:10 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/elements.h"

///////////////////////////////////////////////
/* 

	created using the existing structure
		typedef	t_tuple t_point;  // A point has w = 1.0
		typedef	t_tuple t_vector; // A vector has w = 0.0
 */

// A point has w = 1.0


t_point create_point(double x, double y, double z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;

	return (point);
}

t_vector create_vector(double x, double y, double z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0;

	return (vector);
}

t_point	add_vector_to_point(t_point p, t_vector v)
{
	t_point	result;

	result.x = p.x + v.x;
	result.y = p.y + v.y;
	result.z = p.z + v.z;

	return (result);
}

t_vector	multiple_vector(t_vector v, double scalar)
{
	t_vector	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;

	return (result);
}

t_point	position(t_ray ray, double t)
{
	t_vector	scaled_direction;

	scaled_direction = multiple_vector(ray.direction, t);

	return (add_vector_to_point(ray.origin, scaled_direction));
}