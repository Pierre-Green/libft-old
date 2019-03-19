/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:15:51 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/19 17:23:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"

void				mlx_canvas_background(t_canvas *canvas)
{
	size_t			x;
	size_t			y;

	y = 0;
	while (y < canvas->zone.dim.height)
	{
		x = 0;
		while (x < canvas->zone.dim.width)
		{
			ft_put_pixel_to_image(canvas->img, x, y, canvas->background_color);
			x++;
		}
		y++;
	}
}
