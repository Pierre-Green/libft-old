/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:50:11 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:17:59 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"
#include <math.h>

int32_t		ft_vec2_i32_length(t_vec2_i32 self)
{
	return ((int32_t)round(sqrt(ft_vec2_i32_norm(self))));
}
