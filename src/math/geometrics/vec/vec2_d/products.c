/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 18:24:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_d	ft_vec2_d_product1(t_vec2_d self, double a)
{
	self.x *= a;
	self.y *= a;
	return (self);
}

double		ft_vec2_d_product2(t_vec2_d self, t_vec2_d vec)
{
	return (self.x * vec.x + self.y * vec.y);
}
