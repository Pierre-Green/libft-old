/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:43:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 17:06:41 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static t_point2d		pagination_center(t_pagination *pagination,
		t_point2d pos, t_dim2d griddim)
{
	t_dim2d				overflow;

	overflow.width = pagination->zone.dim.width
		- (griddim.width * (pagination->items_dim.width
			+ pagination->items_margin[3] / 2 + pagination->items_margin[1]));
	overflow.height = pagination->zone.dim.height
		- (griddim.height * (pagination->items_dim.height
			+ pagination->items_margin[0] / 2 + pagination->items_margin[2]));
	pos.x += (overflow.width / 2);
	pos.y += (overflow.height / 2) - MLX_PAGINATION_BOT_SIZE;
	return (pos);
}

t_dim2d					mlx_pagination_gride_dims(t_pagination *pagination)
{
	t_dim2d				dim;

	dim.width = pagination->zone.dim.width / (pagination->items_dim.width
			+ pagination->items_margin[1] + pagination->items_margin[3]);
	dim.height = (pagination->zone.dim.height - MLX_PAGINATION_BOT_SIZE)
		/ (pagination->items_dim.height + pagination->items_margin[0]
				+ pagination->items_margin[2]);
	return (dim);
}

t_point2d				mlx_pagination_offset(t_pagination *pagination,
		t_point2d offset, t_zone2d gride, t_bool center)
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

void					mlx_pagination_add_item(t_pagination *self,
		t_drawable drawable)
{
	ft_add_drawable_to_drawables(&self->items, drawable);
}
