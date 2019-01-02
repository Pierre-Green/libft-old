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

static t_vec2_f    ft_base()
{
    t_vec2_f       vec;

    vec.sum = ft_vec2_f_sum;
    vec.minus = ft_vec2_f_minus;
    vec.product1 = ft_vec2_f_product1;
    vec.product2 = ft_vec2_f_product2;
    vec.norm = ft_vec2_f_norm;
    vec.length = ft_vec2_f_length;
    vec.at = ft_vec2_f_at;
    vec.tostring = ft_vec2_f_tostring;
    return (vec);
}

t_vec2_f       ft_init0_vec2_f()
{
    t_vec2_f   vec;

    vec = ft_base();
    vec.x = 0;
    vec.y = 0;
    return (vec);
}

t_vec2_f       ft_init1_vec2_f(float a)
{
    t_vec2_f   vec;

    vec = ft_base();
    vec.x = a;
    vec.y = a;
    return (vec);
}

t_vec2_f       ft_init2_vec2_f(float x, float y)
{
    t_vec2_f   vec;

    vec = ft_base();
    vec.x = x;
    vec.y = y;
    return (vec);
}