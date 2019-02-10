/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 18:26:57 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_f	ft_vec2_f_product1(t_vec2_f self, float a)
{
	self.x *= a;
	self.y *= a;
	return (self);
}

float		ft_vec2_f_product2(t_vec2_f self, t_vec2_f vec)
{
	return (self.x * vec.x + self.y * vec.y);
}
