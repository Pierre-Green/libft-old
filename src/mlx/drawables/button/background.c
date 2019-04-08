/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:33:01 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 19:17:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

void				mlx_button_background(t_button *button, t_point2d offset,
		t_image_carry *carry)
{
	size_t			x;
	size_t			y;

	y = offset.y + button->pos.y;
	while ((y - (offset.y + button->pos.y)) < button->dim.height)
	{
		x = offset.x + button->pos.x;
		while ((x - (offset.x + button->pos.x)) < button->dim.width)
		{
			ft_put_pixel_to_image(carry, x, y,
					(button->enabled ? button->background_color :
					button->disabled_background_color));
			x++;
		}
		y++;
	}
}
