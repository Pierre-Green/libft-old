/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:32:02 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 16:35:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_d				ft_vec3_d_cross(t_vec3_d self, t_vec3_d vec)
{
	return ((t_vec3_d){ self.y * vec.z - self.z * vec.y,
						self.z * vec.x - self.x * vec.z,
						self.x * vec.y - self.y * vec.x });
}
