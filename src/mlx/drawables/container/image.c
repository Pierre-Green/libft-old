/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:50:00 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 19:56:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

char				*mlx_container_image(t_container *self, t_point2d offset, t_image_carry *carry)
{
	t_drawables		*node;
	const t_point2d	next_offset = DDSUM(offset, self->pos);

	mlx_container_background(self, offset, carry);
	node = self->childs;
	while (node)
	{
		ft_image_merge(node->drawable, next_offset, carry);
		node = node->next;
	}
	return (*carry->data);
}
