/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:35:25 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_d		ft_vec3_d_product1(t_vec3_d self, double a)
{
	self.x *= a;
	self.y *= a;
	self.z *= a;
	return (self);
}

double			ft_vec3_d_product2(t_vec3_d self, t_vec3_d vec)
{
	return (self.x * vec.x + self.y * vec.y + self.z * vec.z);
}
