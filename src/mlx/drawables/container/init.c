/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:19:09 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 14:38:18 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "background.c"

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
	t_drawables		*node;
	const t_point2d	next_offset = DDSUM(offset, self->pos);
	t_drwble		obj;

	mlx_container_background(self, offset, carry);
	node = self->childs;
	while (node)
	{
		obj = node->drawable->drawable;
		if (node->drawable->type == CONTAINER)
			obj.container->image(obj.container, next_offset, carry);
		if (node->drawable->type == BUTTON)
			obj.button->image(obj.button, next_offset, carry);
		node = node->next;
	}
	return (*carry->data);
}

t_container			*ft_init_container(t_point2d pos, t_dim2d dim, t_color color)
{
	t_container		*container;

	if (!(container = (t_container *)malloc(sizeof(t_container))))
		return (NULL);
	container->childs = NULL;
	container->add_child = container_add_child;
	container->image = image;
	container->render = mlx_container_render;
	container->background_color = color;
	container->dim = dim;
	container->pos = pos;
	return (container);
}
