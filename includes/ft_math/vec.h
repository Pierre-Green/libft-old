/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:39:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/10 19:28:06 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_VEC_H
# define FT_MATH_VEC_H
# include <stdint.h>
# define VEC2_GET_X(vec, type) (type) vec2_get_x(vec)
# define VEC2_GET_Y(vec, type) (type) vec2_get_y(vec)

typedef enum			e_vec_type
{
	INT8,
	DOUBLE
}						t_vec_type;

typedef struct			s_vec2
{
	void				*x;
	void				*y;
	t_vec_type			type;
	uint8_t				size;
}						t_vec2;

t_vec2					construct_vec2(t_vec_type type, void *x, void *y);

void					*vec2_get_x(t_vec2 vec);

void					*vec2_get_y(t_vec2 vec);

#endif
