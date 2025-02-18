/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarghes <avarghes@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:51:09 by avarghes          #+#    #+#             */
/*   Updated: 2025/02/18 11:40:45 by avarghes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

/*
	Structure to define matrix with a double pointer array
	and size to define the square matrix.
	if size = 4, then it would be a 4x4 matrix.
 */

typedef struct s_matrix
{
	double		**mtrx;
	int			size;
}				t_matrix;



typedef struct s_shear
{
	double	x_y;
	double	x_z;
	double	y_x;
	double	y_z;
	double	z_x;
	double	z_y;
}				t_shear;


			/* matrix folder */
/* ****	MATRIX_OPERATIONS.C	**** */
t_matrix	create_matrix(int size);
t_matrix	matrix_multiplication(t_matrix *a, t_matrix *b, int size);
double		cofactor(t_matrix *matrix, int row, int col);
t_matrix	inverse(t_matrix *m1);

/* ****	MATRIX_OPERATIONS1.C	**** */
t_matrix	transpose_matrix(t_matrix m);
t_tuple		matrix_multiply_tuple(t_matrix m, t_tuple t);

/* ****	MATRIX_DETERMINANT.C	**** */
void		get_submatrix(t_matrix *src, t_matrix *dest, int row, int col);
double		base_case_determinant(t_matrix *matrix);
double		determinant(t_matrix *matrix);


			/* matrix_transformation folder */
/* ****	MTRX_TRNSFM_OPN.C	**** */
t_matrix	create_identity_matrix(int size);
t_matrix	create_translation_mtrx(float x, float y, float z);
t_matrix	create_scaling_mtrx(float x, float y, float z);

/* ****	MTRX_TRNSFM_OPN1.C	**** */
t_matrix	shearing(t_shear shear_factors);

/* ****	MTRX_TRNSFM_OPN1.C	**** */
t_matrix	rotation_x(double radians);
t_matrix	rotation_y(double radians);
t_matrix	rotation_z(double radians);

#endif