/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 01:41:58 by pierre            #+#    #+#             */
/*   Updated: 2019/03/08 02:03:18 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static t_point2d		pagination_center(t_pagination *pagination, t_point2d pos, t_dim2d griddim)
{
	t_dim2d				overflow;

	overflow.width = pagination->zone.dim.width
		- (griddim.width * (pagination->items_dim.width + pagination->items_margin[3] + pagination->items_margin[1]));
	overflow.height = pagination->zone.dim.height
		- (griddim.height * (pagination->items_dim.height + pagination->items_margin[0] + pagination->items_margin[2]));
	pos.x += overflow.width / 2;
	pos.y += overflow.width / 2;
	return (pos);
}

t_point2d				mlx_pagination_offset(t_pagination *pagination, t_point2d offset, t_zone2d gride, t_bool center)
{
	t_point2d			res;

	res.y = offset.y + (gride.pos.y * pagination->items_dim.height)
		+ ((gride.pos.y + 1) * pagination->items_margin[0])
		+ (gride.pos.y * pagination->items_margin[2]);
	res.x = offset.x + (gride.pos.x * pagination->items_dim.width)
		+ ((gride.pos.x + 1) * pagination->items_margin[3])
		+ (gride.pos.x * pagination->items_margin[1]);
	return ((center ? pagination_center(pagination, res, gride.dim) : res));
}
