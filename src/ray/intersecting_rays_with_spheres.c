/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersecting_rays_with_spheres.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:10:06 by shkaruna          #+#    #+#             */
/*   Updated: 2025/02/18 10:31:59 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/elements.h"

/*      Compute dot product of two vectors      */
double      dot_product(t_vector    a, t_vector b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

/*      Funtion to subtract two points (to get a vector) */
t_vector    subtract(t_point a, t_point b)
{
	t_vector    result;
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

/*      A function to normalize a vector(make it unit length) */
t_vector    normalize(t_vector v)
{
	double  magnitude;

	magnitude = sqrt(dot_product(v, v));
	if(magnitude == 0) //avoid division by zero
	{
		printf("Error: Cannot normalize a zero-length vector. \n");
		return(t_vector){0, 0, 0, 0};
	}
	t_vector    result;
	result.x = v.x / magnitude;
	result.y = v.y / magnitude;
	result.z = v.z / magnitude;
	return result;
}