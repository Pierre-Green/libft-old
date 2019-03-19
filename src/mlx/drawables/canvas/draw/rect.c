/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:45:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/19 17:49:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"

void					mlx_canvas_draw_rect(t_canvas *canvas, t_zone2d zone, t_color color)
{
	size_t				x;
	size_t				y;

	y = zone.pos.y;
	while ((y - zone.pos.y) < zone.dim.height)
	{
		x = zone.pos.x;
		while ((x - zone.pos.x) < zone.dim.width)
		{
			ft_put_pixel_to_image(canvas->img, x, y, color);
			x++;
		}
		y++;
	}
}
