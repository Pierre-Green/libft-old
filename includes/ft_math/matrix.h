/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:41:29 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:41:30 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_MATRIX_H
# define FT_MATH_MATRIX_H
# include <stdint.h>

typedef struct 			s_matrix44_i8
{
	int8_t 				matrix[4][4];
}						t_matrix44_i8;

t_matrix44_i8			ft_init0_matrix44_i8();

t_matrix44_i8			ft_init1_matrix44_i8(int8_t a);

t_matrix44_i8			ft_init44_matrix44_i8(int8_t matrixxx[4][4]);

char 					*ft_matrix44_i8_tostring(t_matrix44_i8 self);

#endif
