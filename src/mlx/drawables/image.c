/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:13:54 by pierre            #+#    #+#             */
/*   Updated: 2019/03/12 18:16:50 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_image_carry			*ft_image_merge(t_drawable *drawable, t_point2d offset, t_image_carry *carry)
{
	const t_drwble		obj = drawable->drawable;

	if (drawable->type == CONTAINER)
		obj.container->image(obj.container, offset, carry);
	if (drawable->type == BUTTON)
		obj.button->image(obj.button, offset, carry);
	if (drawable->type == PAGINATION)
		obj.pagination->image(obj.pagination, offset, carry);
	if (drawable->type == CANVAS)
		obj.canvas->image_intern(obj.canvas, offset, carry);
	return (carry);
}

void					ft_put_pixel_to_image(t_image_carry *carry, size_t x, size_t y, unsigned int color)
{
	const size_t		offset = ((y * carry->size_line) + (x *(carry->bits_per_pixels / 8)));

	(*carry->data)[offset] = (color & 0xFF);
  	(*carry->data)[offset + 1] = (color & 0xFF00) >> 8;
 	(*carry->data)[offset + 2] = (color & 0xFF0000) >> 16;
}
