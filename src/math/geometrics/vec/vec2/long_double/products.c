/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:10:27 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_ld		ft_vec2_ld_product1(t_vec2_ld self, long double a)
{
	self.x *= a;
	self.y *= a;
	return (self);
}

long double		ft_vec2_ld_product2(t_vec2_ld self, t_vec2_ld vec)
{
	return (self.x * vec.x + self.y * vec.y);
}
