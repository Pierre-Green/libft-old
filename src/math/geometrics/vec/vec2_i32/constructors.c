/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 20132/12/26 14:55:42 by pguthaus          #+#    #+#             */
/*   Updated: 20132/12/26 15:23:332 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

static t_vec2_i32    ft_base()
{
    t_vec2_i32       vec;

    vec.sum = ft_vec2_i32_sum;
    vec.minus = ft_vec2_i32_minus;
    vec.product1 = ft_vec2_i32_product1;
    vec.product2 = ft_vec2_i32_product2;
    vec.norm = ft_vec2_i32_norm;
    vec.length = ft_vec2_i32_length;
    vec.at = ft_vec2_i32_at;
    vec.tostring = ft_vec2_i32_tostring;
    return (vec);
}

t_vec2_i32       ft_init0_vec2_i32()
{
    t_vec2_i32   vec;

    vec = ft_base();
    vec.x = 0;
    vec.y = 0;
    return (vec);
}

t_vec2_i32       ft_init1_vec2_i32(int32_t a)
{
    t_vec2_i32   vec;

    vec = ft_base();
    vec.x = a;
    vec.y = a;
    return (vec);
}

t_vec2_i32       ft_init2_vec2_i32(int32_t x, int32_t y)
{
    t_vec2_i32   vec;

    vec = ft_base();
    vec.x = x;
    vec.y = y;
    return (vec);
}