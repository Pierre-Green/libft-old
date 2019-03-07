/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:53:28 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 18:58:45 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static t_dim2d			mlx_pagination_gride_dims(t_pagination *pagination)
{
	t_dim2d				dim;

	dim.width = pagination->zone.dim.width / (pagination->items_dim.width + pagination->items_margin[1] + pagination->items_margin[3]);
	dim.height = pagination->zone.dim.height / (pagination->items_dim.height + pagination->items_margin[0] + pagination->items_margin[2]);
	return (dim);
}

char					*mlx_pagination_image(t_pagination *self, t_point2d p_offset, t_image_carry *carry)
{
	t_point2d			offset;
	t_zone2d			gride;

	offset = DDSUM(p_offset, self->zone.pos);
	gride = ft_zone2d_from_pdim(POS(0, 0), mlx_pagination_gride_dims(self));
	while (gride.pos.y < (int)gride.dim.height)
	{
		gride.pos.x = 0;
		offset.y += (gride.pos.y * self->items_dim.height)
			+ ((gride.pos.y + 1) * self->items_margin[0])
			+ (gride.pos.y * self->items_margin[2]);
		offset.x = p_offset.x + self->zone.pos.x;
		while (gride.pos.x < (int)gride.dim.width)
		{
			offset.x += (gride.pos.x * self->items_dim.width)
				+ ((gride.pos.x + 1) * self->items_margin[3])
				+ (gride.pos.x * self->items_margin[1]);
			ft_image_merge(ft_drawable_at(self->items, gride.pos.y * gride.pos.x), offset, carry);
			gride.pos.x++;
		}
		gride.pos.y++;
	}
	return (*carry->data);
}
