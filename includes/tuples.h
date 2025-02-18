/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:41:59 by avarghes          #+#    #+#             */
/*   Updated: 2025/02/18 11:36:34 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

/*
Structure to represent Tuples, Points & Vectors
 */
typedef struct s_tuples
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_tuple;

/* 		***TUPLE_OPERATIONS_1.C***		 */
t_tuple	addition(t_tuple p1, t_tuple p2);
t_tuple	subtraction(t_tuple p1, t_tuple p2);
t_tuple	negation(t_tuple a);
t_tuple	scalar_multiply(t_tuple a, double scalar);
t_tuple	divide_by_two(t_tuple a);

/* 		***TUPLE_OPERATIONS_2.C***		 */
double	magnitude(t_tuple p);
t_tuple	normalization(t_tuple p);
double	dot_product(t_tuple a, t_tuple b);
t_tuple	cross_product(t_tuple a, t_tuple b);

#endif