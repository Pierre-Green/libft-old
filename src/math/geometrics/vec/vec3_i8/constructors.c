/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

static t_vec3_i8    ft_base()
{
    t_vec3_i8       vec;

    vec.sum = ft_vec3_i8_sum;
    vec.minus = ft_vec3_i8_minus;
    vec.product1 = ft_vec3_i8_product1;
    vec.product3 = ft_vec3_i8_product3;
    vec.norm = ft_vec3_i8_norm;
    vec.length = ft_vec3_i8_length;
    vec.at = ft_vec3_i8_at;
    vec.tostring = ft_vec3_i8_tostring;
    return (vec);
}

t_vec3_i8       ft_init0_vec3_i8()
{
    t_vec3_i8   vec;

    vec = ft_base();
    vec.x = 0;
    vec.y = 0;
    vec.z = 0;
    return (vec);
}

t_vec3_i8       ft_init1_vec3_i8(int8_t a)
{
    t_vec3_i8   vec;

	vec = ft_base();
	vec.x = a;
    vec.y = a;
    vec.z = a;
    return (vec);
}

t_vec3_i8       ft_init3_vec3_i8(int8_t x, int8_t y, int8_t z)
{
    t_vec3_i8   vec;

	vec = ft_base();
	vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}