/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:50:11 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:21:04 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"
#include <math.h>

int8_t		ft_vec2_i8_length(t_vec2_i8 self)
{
	return ((int8_t)round(sqrt(ft_vec2_i8_norm(self))));
}
