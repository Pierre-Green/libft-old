/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:21:48 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_i8		ft_vec2_i8_product1(t_vec2_i8 self, int8_t a)
{
	self.x *= a;
	self.y *= a;
	return (self);
}

int8_t			ft_vec2_i8_product2(t_vec2_i8 self, t_vec2_i8 vec)
{
	return (self.x * vec.x + self.y * vec.y);
}
