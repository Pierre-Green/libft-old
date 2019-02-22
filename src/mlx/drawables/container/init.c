/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:19:09 by pierre            #+#    #+#             */
/*   Updated: 2019/02/22 14:58:01 by pierre           ###   ########.fr       */
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

static int			container_draw(t_container *self, t_point2d offset)
{
}

static char			*image(t_container *self)
{
}

t_container			*ft_init_container(t_point2d pos, t_dim2d dim)
{
	t_container		*container;

	if (!(container = (t_container *)malloc(sizeof(t_container))))
		return (NULL);
	container->childs = NULL;
	container->add_child = container_add_child;
	container->draw = container_draw;
	container->image = image;
	container->background_color = DEFAULT_BACKGROUND_COLOR;
	container->dim = dim;
	container->pos = pos;
	return (container);
}
