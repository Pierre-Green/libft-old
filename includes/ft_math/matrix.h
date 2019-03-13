/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:41:29 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:03:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_MATRIX_H
# define FT_MATH_MATRIX_H
# include <stdint.h>

typedef struct			s_matrix44_d
{
	double				matrix[4][4];
}						t_matrix44_d;

t_matrix44_d			ft_init0_matrix44_d();

t_matrix44_d			ft_init1_matrix44_d(double a);

t_matrix44_d			ft_init44_matrix44_d(double a[4][4]);

t_matrix44_d			ft_multiply_matrix44_d(t_matrix44_d m1,
		t_matrix44_d m2);

#endif
