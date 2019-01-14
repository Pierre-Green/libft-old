/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:34:39 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:44:59 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_i16		ft_vec3_i16_minus(t_vec3_i16 self, t_vec3_i16 vec)
{
	self.x -= vec.x;
	self.y -= vec.y;
	self.z -= vec.z;
	return (self);
}
