/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:53:33 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/20 19:07:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_FLOATS_H
# define FT_MATH_FLOATS_H
# include "ft_bool.h"
# include <stdint.h>
# define F_EXP_BIAS (127)
# define D_EXP_BIAS (1023)
# define L_EXP_BIAS (16383)

typedef unsigned __int128 uint128_t;

typedef union		u_float
{
	struct			s_fparts
	{
		uint32_t	frac: 23;
		uint8_t		exp: 8;
		uint8_t		sign: 1;
	}				t_fparts;
	float			f;
}					t_float;

typedef union		u_double
{
	struct			s_dparts 
	{
		uint64_t	frac: 52;
		uint16_t	exp: 11;
		uint8_t		sign: 1;
	}				t_dparts;
	double			d;
}					t_double;

typedef union		u_ldouble
{
	struct			s_ldparts 
	{
		uint128_t	frac: 112;
		uint16_t	exp: 15;
		uint8_t		sign: 1;
	}				t_ldparts;
	long double		ld;
}					t_ldouble;

uint32_t			ft_sfrexp_f(float x, int16_t *exp);

uint64_t			ft_sfrexp_d(double x, int16_t *exp);

uint128_t			ft_sfrexp_ld(long double x, int16_t *exp);

#endif
