/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:19:09 by pierre            #+#    #+#             */
/*   Updated: 2019/02/25 15:35:14 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static void			container_add_child(t_container *self, t_drawable *drawable)
{
	if (self->childs == NULL)
		self->childs = (t_drawables *)malloc(sizeof(t_drawables));
	self->childs->drawable = NULL;
	self->childs->next = NULL;
	ft_add_drawable_to_drawables(self->childs, drawable);
}

static char			*image(t_container *self, t_point2d offset, t_image_carry *carry)
{
	size_t			x;
	size_t			y;

	y = offset.y;
	while ((y - offset.y) < self->dim.height)
	{
		x = offset.x;
		while ((x - offset.x) < self->dim.width)
		{
			ft_put_pixel_to_image(*carry->data, carry->size_line, carry->bits_per_pixels, (t_point2d){x, y});
			x++;
		}
		y++;
	}
	return (*carry->data);
}

t_container			*ft_init_container(t_point2d pos, t_dim2d dim)
{
	t_container		*container;

	if (!(container = (t_container *)malloc(sizeof(t_container))))
		return (NULL);
	container->childs = NULL;
	container->add_child = container_add_child;
	container->image = image;
	container->background_color = DEFAULT_BACKGROUND_COLOR;
	container->dim = dim;
	container->pos = pos;
	return (container);
}
