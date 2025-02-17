/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shkaruna <shkaruna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:24:27 by shkaruna          #+#    #+#             */
/*   Updated: 2025/02/05 13:31:15 by shkaruna         ###   ########.fr       */
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

t_point	create_point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;

	return (point);
}

// A vector has w = 0.0

t_vector	create_vector(double x, double y, double z)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0;

	return (vector);
}