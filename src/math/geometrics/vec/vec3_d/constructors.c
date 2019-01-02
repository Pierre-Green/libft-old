/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:55:42 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

static t_vec2_i8    ft_base()
{
    t_vec2_i8       vec;

    vec.sum = ft_vec2_i8_sum;
    vec.minus = ft_vec2_i8_minus;
    vec.product1 = ft_vec2_i8_product1;
    vec.product2 = ft_vec2_i8_product2;
    vec.norm = ft_vec2_i8_norm;
    vec.length = ft_vec2_i8_length;
    vec.at = ft_vec2_i8_at;
    vec.tostring = ft_vec2_i8_tostring;
    return (vec);
}

t_vec2_i8       ft_init0_vec2_i8()
{
    t_vec2_i8   vec;

    vec = ft_base();
    vec.x = 0;
    vec.y = 0;
    return (vec);
}

t_vec2_i8       ft_init1_vec2_i8(int8_t a)
{
    t_vec2_i8   vec;

    vec = ft_base();
    vec.x = a;
    vec.y = a;
    return (vec);
}

t_vec2_i8       ft_init2_vec2_i8(int8_t x, int8_t y)
{
    t_vec2_i8   vec;

    vec = ft_base();
    vec.x = x;
    vec.y = y;
    return (vec);
}