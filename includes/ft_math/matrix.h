/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:41:29 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 21:13:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_MATRIX_H
# define FT_MATH_MATRIX_H
# include <stdint.h>

typedef struct			s_mat44_d_data
{
	double				v00;
	double				v01;
	double				v02;
	double				v03;
	double				v10;
	double				v11;
	double				v12;
	double				v13;
	double				v20;
	double				v21;
	double				v22;
	double				v23;
	double				v30;
	double				v31;
	double				v32;
	double				v33;
}						t_mat44_d_data;

typedef union			s_matrix44_d
{
	t_mat44_d_data		raw;
	double				matrix[4][4];
}						t_matrix44_d;

t_matrix44_d			ft_init0_matrix44_d();

t_matrix44_d			ft_init1_matrix44_d(double a);

t_matrix44_d			ft_init44_matrix44_d(t_mat44_d_data data);

t_matrix44_d			ft_multiply_matrix44_d(t_matrix44_d m1,
		t_matrix44_d m2);

t_matrix44_d			ft_perspective_matrix44_d(double fov, double near, double far);

void					ft_mat44d_debug(t_matrix44_d self);

#endif
