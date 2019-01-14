/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:07:39 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:07:45 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_i32			ft_init0_vec3_i32(void)
{
	t_vec3_i32		vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

t_vec3_i32			ft_init1_vec3_i32(int32_t a)
{
	t_vec3_i32		vec;

	vec.x = a;
	vec.y = a;
	vec.z = a;
	return (vec);
}

t_vec3_i32			ft_init3_vec3_i32(int32_t x, int32_t y, int32_t z)
{
	t_vec3_i32		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
