/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:44:06 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/19 17:22:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static t_image_carry	*init_img(t_canvas *canvas, t_image_carry *parent)
{
	size_t				sl;
	char				*data;

	sl = (parent->bits_per_pixels / 8) * (canvas->zone.dim.width);
	if (!(data = malloc(sizeof(char) * (sl * canvas->zone.dim.height))))
		return (NULL);
	canvas->img = ft_image_carry_from(NULL, data,
			parent->bits_per_pixels, sl, parent->endian);
	return (canvas->img);
}

t_image_carry			*mlx_canvas_image_intern(t_canvas *canvas,
		t_point2d offset, t_image_carry *carry)
{
	t_point2d			next_offset;
	size_t				x;
	size_t				y;

	next_offset = DDSUM(offset, canvas->zone.pos);
	if (!canvas->img && !(canvas->img = init_img(canvas, carry)))
		return (NULL);
	mlx_canvas_background(canvas);
	if (canvas->image)
		canvas->img = canvas->image(canvas, canvas->s, canvas->img);
	else
		return (carry);
	y = 0;
	while (y < canvas->zone.dim.height)
	{
		x = 0;
		while (x < canvas->zone.dim.width)
		{
			ft_copy_pixel_to_image(carry, canvas->img,
					POS(next_offset.x + x, next_offset.y + y), POS(x, y));
			x++;
		}
		y++;
	}
	return (carry);
}
