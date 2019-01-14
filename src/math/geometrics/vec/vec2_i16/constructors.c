/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:55:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:05:52 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_i16		ft_init0_vec2_i16(void)
{
	t_vec2_i16	vec;

	vec.x = 0;
	vec.y = 0;
	return (vec);
}

t_vec2_i16		ft_init1_vec2_i16(int16_t a)
{
	t_vec2_i16	vec;

	vec.x = a;
	vec.y = a;
	return (vec);
}

t_vec2_i16		ft_init2_vec2_i16(int16_t x, int16_t y)
{
	t_vec2_i16	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}
