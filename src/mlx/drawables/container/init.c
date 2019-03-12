/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:19:09 by pierre            #+#    #+#             */
/*   Updated: 2019/03/12 19:04:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "background.c"

static void			container_add_child(t_container *self, t_drawable *drawable)
{
	if (self->childs == NULL)
	{
		self->childs = (t_drawables *)malloc(sizeof(t_drawables));
		self->childs->drawable = NULL;
		self->childs->next = NULL;
	}
	ft_add_drawable_to_drawables(self->childs, drawable);
}

t_container			*ft_init_container(t_point2d pos, t_dim2d dim, t_color color)
{
	t_container		*container;

	if (!(container = (t_container *)malloc(sizeof(t_container))))
		return (NULL);
	container->childs = NULL;
	container->add_child = container_add_child;
	container->image = mlx_container_image;
	container->render = mlx_container_render;
	container->render_txt = mlx_container_render_txt;
	container->background_color = color;
	container->dim = dim;
	container->pos = pos;
	return (container);
}
