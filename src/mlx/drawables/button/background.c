/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:05:53 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 14:06:51 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

void					mlx_button_background(t_button *button, t_point2d offset, t_image_carry *carry)
{
	size_t			x;
	size_t			y;

	y = offset.y + button->pos.y;
	while ((y - (offset.y + button->pos.y)) < button->dim.height)
	{
		x = offset.x + button->pos.x;
		while ((x - (offset.x + button->pos.x)) < button->dim.width)
		{
			ft_put_pixel_to_image(carry, x, y, button->background_color);
			x++;
		}
		y++;
	}
}
