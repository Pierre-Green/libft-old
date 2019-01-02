/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:55:42 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/26 15:23:316 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

static t_vec2_i16    ft_base()
{
    t_vec2_i16       vec;

    vec.sum = ft_vec2_i16_sum;
    vec.minus = ft_vec2_i16_minus;
    vec.product1 = ft_vec2_i16_product1;
    vec.product2 = ft_vec2_i16_product2;
    vec.norm = ft_vec2_i16_norm;
    vec.length = ft_vec2_i16_length;
    vec.at = ft_vec2_i16_at;
    vec.tostring = ft_vec2_i16_tostring;
    return (vec);
}

t_vec2_i16       ft_init0_vec2_i16()
{
    t_vec2_i16   vec;

    vec = ft_base();
    vec.x = 0;
    vec.y = 0;
    return (vec);
}

t_vec2_i16       ft_init1_vec2_i16(int16_t a)
{
    t_vec2_i16   vec;

    vec = ft_base();
    vec.x = a;
    vec.y = a;
    return (vec);
}

t_vec2_i16       ft_init2_vec2_i16(int16_t x, int16_t y)
{
    t_vec2_i16   vec;
    
    vec = ft_base();
    vec.x = x;
    vec.y = y;
    return (vec);
}