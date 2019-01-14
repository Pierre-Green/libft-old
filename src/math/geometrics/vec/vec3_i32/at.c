/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:07:57 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:08:00 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

int32_t		ft_vec3_i32_at(t_vec3_i32 self, uint8_t i)
{
	if (i == 0)
		return (self.x);
	if (i == 1)
		return (self.y);
	if (i == 2)
		return (self.z);
	else
		return (0);
}
