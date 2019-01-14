/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:41:57 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_f	ft_vec3_f_product1(t_vec3_f self, float a)
{
	self.x *= a;
	self.y *= a;
	self.z *= a;
	return (self);
}

float		ft_vec3_f_product2(t_vec3_f self, t_vec3_f vec)
{
	return (self.x * vec.x + self.y * vec.y + self.z * vec.z);
}
