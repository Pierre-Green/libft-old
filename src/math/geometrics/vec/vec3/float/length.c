/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:50:11 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:39:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"
#include <math.h>

float		ft_vec3_f_length(t_vec3_f self)
{
	return (sqrt(ft_vec3_f_norm(self)));
}
