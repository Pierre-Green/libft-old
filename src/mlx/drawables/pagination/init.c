/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:43:14 by pierre            #+#    #+#             */
/*   Updated: 2019/03/08 01:48:48 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static void				pagination_add_item(t_pagination *self, t_drawable *drawable)
{
	if (self->items == NULL)
	{
		self->items = (t_drawables *)malloc(sizeof(t_drawables));
		self->items->drawable = NULL;
		self->items->next = NULL;
	}
	ft_add_drawable_to_drawables(self->items, drawable);
}

t_pagination			*mlx_init_pagination(t_zone2d zone, t_dim2d item_dim, t_margin item_margin)
{
	t_pagination		*pagination;
	size_t				curr;

	if (!(pagination = malloc(sizeof(t_pagination))))
		return (NULL);
	pagination->zone = zone;
	pagination->items_dim = item_dim;
	curr = 0;
	while (curr++ < 4)
		pagination->items_margin[curr - 1] = item_margin[curr - 1];
	pagination->items_count = 0;
	pagination->items = NULL;
	pagination->render_txt = mlx_pagination_render_txt;
	pagination->add_child = pagination_add_item;
	pagination->image = mlx_pagination_image;
	return (pagination);
}
