/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:13:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/12 19:11:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_VEC_H
# define FT_MATH_VEC_H
# include <stdint.h>

/*
 ** 2D vector types
 */
typedef struct			s_vec2_f
{
	float				x;
	float				y;
}						t_vec2_f;


typedef struct			s_vec2_d
{
	double				x;
	double				y;
}						t_vec2_d;

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
 ** vec2_f
 */
t_vec2_f				ft_init0_vec2_f(void);

t_vec2_f				ft_init1_vec2_f(float a);

t_vec2_f				ft_init2_vec2_f(float x, float y);

t_vec2_f				ft_vec2_f_sum(t_vec2_f self, t_vec2_f vec);

t_vec2_f				ft_vec2_f_minus(t_vec2_f self, t_vec2_f vec);

t_vec2_f				ft_vec2_f_product1(t_vec2_f self, float a);

float					ft_vec2_f_product2(t_vec2_f self, t_vec2_f vec);

float					ft_vec2_f_norm(t_vec2_f self);

float					ft_vec2_f_length(t_vec2_f self);

float					ft_vec2_f_at(t_vec2_f self, uint8_t i);

char					*ft_vec2_f_tostring(t_vec2_f self);

float					ft_vec2_f_crossproduct(t_vec2_f self, t_vec2_f vec);

t_vec2_f				ft_vec2_f_normalize(t_vec2_f self);

/*
 ** vec2_d
 */
t_vec2_d				ft_init0_vec2_d(void);

t_vec2_d				ft_init1_vec2_d(double a);

t_vec2_d				ft_init2_vec2_d(double x, double y);

t_vec2_d				ft_vec2_d_sum(t_vec2_d self, t_vec2_d vec);

t_vec2_d				ft_vec2_d_minus(t_vec2_d self, t_vec2_d vec);

t_vec2_d				ft_vec2_d_product1(t_vec2_d self, double a);

double					ft_vec2_d_product2(t_vec2_d self, t_vec2_d vec);

double					ft_vec2_d_norm(t_vec2_d self);

double					ft_vec2_d_length(t_vec2_d self);

double					ft_vec2_d_at(t_vec2_d self, uint8_t i);

char					*ft_vec2_d_tostring(t_vec2_d self);

double					ft_vec2_d_crossproduct(t_vec2_d self, t_vec2_d vec);

t_vec2_d				ft_vec2_d_normalize(t_vec2_d self);

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

float					ft_vec3_f_at(t_vec3_f self, uint8_t i);

char					*ft_vec3_f_tostring(t_vec3_f self);

float					ft_vec3_f_crossproduct(t_vec3_f self, t_vec3_f vec);

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

double					ft_vec3_d_at(t_vec3_d self, uint8_t i);

char					*ft_vec3_d_tostring(t_vec3_d self);

double					ft_vec3_d_crossproduct(t_vec3_d self, t_vec3_d vec);

t_vec3_d				ft_vec3_d_normalize(t_vec3_d self);

#endif
