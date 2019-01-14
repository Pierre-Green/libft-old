/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 19:19:12 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_i32		ft_vec2_i32_product1(t_vec2_i32 self, int32_t a)
{
	self.x *= a;
	self.y *= a;
	return (self);
}

int32_t			ft_vec2_i32_product2(t_vec2_i32 self, t_vec2_i32 vec)
{
	return (self.x * vec.x + self.y * vec.y);
}
