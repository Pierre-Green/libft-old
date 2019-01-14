/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:32:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:03:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_ld		ft_vec3_ld_sum(t_vec3_ld self, t_vec3_ld vec)
{
	self.x += vec.x;
	self.y += vec.y;
	self.z += vec.z;
	return (self);
}
