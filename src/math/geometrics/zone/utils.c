/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:26:54 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:27:44 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/zone.h"

t_bool				ft_is_point_in_zone2d(t_zone2d zone, t_point2d point)
{
	return ((point.x >= zone.pos.x
			&& point.x <= zone.pos.x + (int)zone.dim.width)
			&& (point.y >= zone.pos.y
			&& point.y <= zone.pos.y + (int)zone.dim.height));
}

t_zone2d			ft_zone2d_from_pdim(t_point2d pos, t_dim2d dim)
{
	return ((t_zone2d){ pos, dim });
}
