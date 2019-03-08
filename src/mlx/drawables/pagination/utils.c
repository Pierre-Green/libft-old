/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 01:41:58 by pierre            #+#    #+#             */
/*   Updated: 2019/03/08 01:43:54 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_point2d				mlx_pagination_offset(t_pagination *pagination, t_point2d offset, t_zone2d gride)
{
	t_point2d			res;

	res.y = offset.y + (gride.pos.y * pagination->items_dim.height)
		+ ((gride.pos.y + 1) * pagination->items_margin[0])
		+ (gride.pos.y * pagination->items_margin[2]);
	res.x = offset.x + (gride.pos.x * pagination->items_dim.width)
		+ ((gride.pos.x + 1) * pagination->items_margin[3])
		+ (gride.pos.x * pagination->items_margin[1]);
	return (res);
}
