/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:13:54 by pierre            #+#    #+#             */
/*   Updated: 2019/02/25 17:46:49 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_image_carry			*ft_image_merge(t_image_carry *carry, t_point2d offset, char *value)
{
	(void)value;
	(void)offset;
	(void)carry;
	return (NULL);
}

void					ft_put_pixel_to_image(t_image_carry *carry, size_t x, size_t y)
{
	unsigned int		color;
	const ssize_t		offset = ((y * carry->size_line) + (x *(carry->bits_per_pixels / 8)));

	color = 0xFFFFFF;
	(*carry->data)[offset] = (color & 0xFF);
  	(*carry->data)[offset + 1] = (color & 0xFF00) >> 8;
 	(*carry->data)[offset + 2] = (color & 0xFF0000) >> 16;
}
