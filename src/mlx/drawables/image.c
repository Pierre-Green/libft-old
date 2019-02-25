/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:13:54 by pierre            #+#    #+#             */
/*   Updated: 2019/02/25 17:27:05 by pierre           ###   ########.fr       */
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

void						ft_put_pixel_to_image(char *data, int sl, int bpp, t_point2d pos)
{
	unsigned int		color;

	color = 0xFF0000;
	data[pos.y * sl + pos.x * (bpp / 8)] = (color & 0xFF);
  	data[(pos.y * sl + pos.x * (bpp / 8)) + 1] = (color & 0xFF00) >> 8;
 	data[(pos.y * sl + pos.x * (bpp / 8)) + 2] = (color & 0xFF0000) >> 16;
}
