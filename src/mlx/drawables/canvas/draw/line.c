/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:32:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 20:24:12 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"

static void				canva_line1(t_canvas *canvas, t_point2d from, t_point2d to, t_color color)
{
	int					x;
	int					calculated;

	x = from.x;
	while (x < to.x)
	{
		calculated = (from.y + ((to.y - from.y) * (x - from.x)) / (to.x - from.x));
		ft_put_pixel_to_image(canvas->img, x, calculated, color);
		x++;
	}
}

static void				canva_line2(t_canvas *canvas, t_point2d from, t_point2d to, t_color color)
{
	int					y;
	int					calculated;

	y = from.y;
	while (y < to.y)
	{
		calculated = from.x + ((to.x - from.x) * (y - from.y)) / (to.y - from.y);
		ft_put_pixel_to_image(canvas->img, calculated, y, color);
		y++;
	}
}

void					mlx_canvas_draw_line(t_canvas *canvas, t_point2d from, t_point2d to, t_color color)
{
	const t_dim2d		dims = canvas->zone.dim;

	if ((from.x < 0 || from.y < 0 || to.x < 0 || to.y < 0)
			|| (from.x >= (int)dims.width || from.y >= (int)dims.height
				|| to.x >= (int)dims.width || to.y >= (int)dims.height))
		return ;
	if ((to.x - from.x) >= abs(to.y - from.y))
	{
		if (from.x <= to.x)
			canva_line1(canvas, from, to, color);
		else
			canva_line1(canvas, to, from, color);
	}
	else
	{
		if (from.y <= to.y)
			canva_line2(canvas, from, to, color);
		else
			canva_line2(canvas, to, from, color);
	}
}
