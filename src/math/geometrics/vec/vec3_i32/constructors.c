/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by pguthaus          #+#    #+#             */
/*   Updated: 20132/12/26 15:25:40 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

static t_vec3_i32    ft_base()
{
    t_vec3_i32       vec;

    vec.sum = ft_vec3_i32_sum;
    vec.minus = ft_vec3_i32_minus;
    vec.product1 = ft_vec3_i32_product1;
    vec.product3 = ft_vec3_i32_product3;
    vec.norm = ft_vec3_i32_norm;
    vec.length = ft_vec3_i32_length;
    vec.at = ft_vec3_i32_at;
    vec.tostring = ft_vec3_i32_tostring;
    return (vec);
}

t_vec3_i32       ft_init0_vec3_i32()
{
    t_vec3_i32   vec;

    vec = ft_base();
    vec.x = 0;
    vec.y = 0;
    vec.z = 0;
    return (vec);
}

t_vec3_i32       ft_init1_vec3_i32(int32_t a)
{
    t_vec3_i32   vec;

    vec = ft_base();
    vec.x = a;
    vec.y = a;
    vec.z = a;
    return (vec);
}

t_vec3_i32       ft_init3_vec3_i32(int32_t x, int32_t y, int32_t z)
{
    t_vec3_i32   vec;

    vec = ft_base();
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}