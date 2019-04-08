/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:00:52 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 16:01:33 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_d				ft_vec3_d_div(t_vec3_d self, t_vec3_d vec)
{
	return ((t_vec3_d){ self.x / vec.x, self.y / vec.y, self.z / vec.z });
}
