/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:11:27 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:11:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_i32		ft_init0_vec2_i32(void)
{
	t_vec2_i32	vec;

	vec.x = 0;
	vec.y = 0;
	return (vec);
}

t_vec2_i32		ft_init1_vec2_i32(int32_t a)
{
	t_vec2_i32	vec;

	vec.x = a;
	vec.y = a;
	return (vec);
}

t_vec2_i32		ft_init2_vec2_i32(int32_t x, int32_t y)
{
	t_vec2_i32	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}
