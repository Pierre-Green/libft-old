/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:53:28 by pierre            #+#    #+#             */
/*   Updated: 2019/03/08 01:44:28 by pierre           ###   ########.fr       */
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
	t_point2d			next_offset;
	t_zone2d			gride;

	offset = DDSUM(p_offset, self->zone.pos);
	gride = ft_zone2d_from_pdim(POS(0, 0), mlx_pagination_gride_dims(self));
	while (gride.pos.y < (int)gride.dim.height)
	{
		gride.pos.x = 0;
		while (gride.pos.x < (int)gride.dim.width)
		{
			next_offset = mlx_pagination_offset(self, offset, gride);
			ft_image_merge(ft_drawable_at(self->items, (gride.pos.y * gride.dim.width) + gride.pos.x), next_offset, carry);
			gride.pos.x++;
		}
		gride.pos.y++;
	}
	return (*carry->data);
}
