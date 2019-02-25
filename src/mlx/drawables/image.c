/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:13:54 by pierre            #+#    #+#             */
/*   Updated: 2019/02/25 18:47:46 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_image_carry			*ft_image_merge(t_image_carry *dest, t_point2d offset, t_image_carry *src)
{
	(void)dest;
	(void)offset;
	(void)src;
	return (NULL);
}

t_image_carry			*ft_image_router(t_drawable *drawable, t_image_carry *dest)
{

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
