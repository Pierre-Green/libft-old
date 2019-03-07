/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:03:21 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 16:36:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/zone.h"

t_bool				ft_is_point_in_zone2d(t_zone2d zone, t_point2d point)
{
	return ((point.x >= zone.pos.x && point.x <= zone.pos.x + (int)zone.dim.width)
			&& (point.y >= zone.pos.y && point.y <= zone.pos.y + (int)zone.dim.height));
}

t_zone2d			ft_zone2d_from_pdim(t_point2d pos, t_dim2d dim)
{
	return ((t_zone2d){ pos, dim });
}
