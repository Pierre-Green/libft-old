/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:32:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/02 16:33:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"

static void				canva_line1(t_canvas *canvas, t_point2d from,
		t_point2d to, t_color color, t_dim2d dims)
{
	int					x;
	int					calculated;

	x = from.x;
	while ((x < to.x && x <= (int)dims.width) && (calculated = (from.y + ((to.y - from.y) * (x - from.x)) / (to.x - from.x))) <= (int)dims.height)
	{
				ft_put_pixel_to_image(canvas->img, x, calculated, color);
		x++;
	}
}

static void				canva_line2(t_canvas *canvas, t_point2d from,
		t_point2d to, t_color color, t_dim2d dims)
{
	int					y;
	int					calculated;

	y = from.y;
	while ((y < to.y && y <= (int)dims.height)
			&& (calculated = from.x + ((to.x - from.x) * (y - from.y))
				/ (to.y - from.y)) <= (int)dims.width)
	{
		ft_put_pixel_to_image(canvas->img, calculated, y, color);
		y++;
	}
}

void					mlx_canvas_draw_line(t_canvas *canvas, t_point2d from, t_point2d to, t_color color)
{
	const t_dim2d		dims = canvas->zone.dim;

	if ((to.x - from.x) >= abs(to.y - from.y))
	{
		if (from.x <= to.x)
			canva_line1(canvas, from, to, color, dims);
		else
			canva_line1(canvas, to, from, color, dims);
	}
	else
	{
		if (from.y <= to.y)
			canva_line2(canvas, from, to, color, dims);
		else
			canva_line2(canvas, to, from, color, dims);
	}
}
