/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:13:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 21:11:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_VEC_H
# define FT_MATH_VEC_H
# include <stdint.h>
# include "ft_math/matrix.h"
# include "ft_bool.h"

/*
** 3D vector types
*/
typedef struct			s_vec3_f
{
	float				x;
	float				y;
	float				z;
}						t_vec3_f;

typedef struct			s_vec3_d
{
	double				x;
	double				y;
	double				z;
}						t_vec3_d;

/*
** vec3_f
*/
t_vec3_f				ft_init0_vec3_f(void);

t_vec3_f				ft_init1_vec3_f(float a);

t_vec3_f				ft_init3_vec3_f(float x, float y, float z);

t_vec3_f				ft_vec3_f_sum(t_vec3_f self, t_vec3_f vec);

t_vec3_f				ft_vec3_f_minus(t_vec3_f self, t_vec3_f vec);

t_vec3_f				ft_vec3_f_product1(t_vec3_f self, float a);

float					ft_vec3_f_product3(t_vec3_f self, t_vec3_f vec);

float					ft_vec3_f_norm(t_vec3_f self);

float					ft_vec3_f_length(t_vec3_f self);

t_vec3_f				ft_vec3_f_cross(t_vec3_f self, t_vec3_f vec);

t_vec3_f				ft_vec3_f_normalize(t_vec3_f self);

/*
** vec3_d
*/
t_vec3_d				ft_init0_vec3_d(void);

t_vec3_d				ft_init1_vec3_d(double a);

t_vec3_d				ft_init3_vec3_d(double x, double y, double z);

t_vec3_d				ft_vec3_d_sum(t_vec3_d self, t_vec3_d vec);

t_vec3_d				ft_vec3_d_minus(t_vec3_d self, t_vec3_d vec);

t_vec3_d				ft_vec3_d_product1(t_vec3_d self, double a);

double					ft_vec3_d_product3(t_vec3_d self, t_vec3_d vec);

double					ft_vec3_d_norm(t_vec3_d self);

double					ft_vec3_d_length(t_vec3_d self);

t_vec3_d				ft_vec3_d_cross(t_vec3_d self, t_vec3_d vec);

t_vec3_d				ft_vec3_d_normalize(t_vec3_d self);

t_vec3_d				ft_vec3_d_matmut(t_vec3_d self, t_matrix44_d mat, t_bool cartesian);

void					ft_vec3_d_debug(t_vec3_d self);

#endif
