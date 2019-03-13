/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:29:45 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 19:30:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

void			mlx_container_add_child(t_container *self, t_drawable *drawable)
{
	if (self->childs == NULL)
	{
		self->childs = (t_drawables *)malloc(sizeof(t_drawables));
		self->childs->drawable = NULL;
		self->childs->next = NULL;
	}
	ft_add_drawable_to_drawables(self->childs, drawable);
}
