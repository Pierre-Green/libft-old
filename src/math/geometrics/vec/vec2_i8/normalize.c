/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:46:33 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 15:11:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec2_i8		ft_vec2_i8_normalize(t_vec2_i8 self)
{
	int8_t		len;
	int8_t		inv_len;

	len = ft_vec2_i8_length(self);
	if (len > 0)
	{
		inv_len = 1 / len;
		self.x *= inv_len;
		self.y *= inv_len;
	}
	return (self);
}
