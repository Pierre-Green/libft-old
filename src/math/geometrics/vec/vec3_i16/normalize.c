/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:46:33 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 14:50:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_i16		ft_vec3_i16_normalize(t_vec3_i16 self)
{
	int16_t		len;
	int16_t		inv_len;

	len = ft_vec3_i16_length(self);
	if (len > 0)
	{
		inv_len = 1 / len;
		self.x *= inv_len;
		self.y *= inv_len;
		self.z *= inv_len;
	}
	return (self);
}
