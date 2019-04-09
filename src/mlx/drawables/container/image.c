/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:50:00 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 17:18:53 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

char				*mlx_container_image(t_container *self, t_point2d offset,
		t_image_carry *carry)
{
	const t_point2d	next_offset = DDSUM(offset, self->pos);
	size_t			current;

	mlx_container_background(self, offset, carry);
	current = 0;
	while (self->childs && current < self->childs->len)
	{
		ft_image_merge(self->childs->drawables[current], next_offset, carry);
		current++;
	}
	return (carry->data);
}
