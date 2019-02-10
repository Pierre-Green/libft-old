/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:02:13 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_ld		ft_vec3_ld_product1(t_vec3_ld self, long double a)
{
	self.x *= a;
	self.y *= a;
	self.z *= a;
	return (self);
}

long double		ft_vec3_ld_product2(t_vec3_ld self, t_vec3_ld vec)
{
	return (self.x * vec.x + self.y * vec.y + self.z * vec.z);
}
