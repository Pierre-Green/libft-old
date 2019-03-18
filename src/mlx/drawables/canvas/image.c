/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:44:06 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 21:49:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_image_carry			*mlx_canvas_image_intern(t_canvas *canvas,
		t_point2d offset, t_image_carry *carry)
{
	t_point2d			next_offset;
	size_t				x;
	size_t				y;

	next_offset = DDSUM(offset, canvas->zone.pos);
	if (canvas->image)
		canvas->img = canvas->image(canvas, canvas->s, canvas->img);
	else
		return (carry);
	y = 0;
	while (next_offset.y + y <= canvas->zone.dim.height)
	{
		x = 0;
		while (next_offset.x + x <= canvas->zone.dim.width)
		{
			(*carry->data)[((next_offset.y + y) * carry->size_line)
				+ next_offset.x + x] = *canvas->img->data[(y
						* canvas->img->size_line) + x];
			x++;
		}
		y++;
	}
	return (carry);
}
