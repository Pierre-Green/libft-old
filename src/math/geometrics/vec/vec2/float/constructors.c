/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:55:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 18:28:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_f		ft_init0_vec2_f(void)
{
	t_vec2_f	vec;

	vec.x = 0;
	vec.y = 0;
	return (vec);
}

t_vec2_f		ft_init1_vec2_f(float a)
{
	t_vec2_f	vec;

	vec.x = a;
	vec.y = a;
	return (vec);
}

t_vec2_f		ft_init2_vec2_f(float x, float y)
{
	t_vec2_f	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}
