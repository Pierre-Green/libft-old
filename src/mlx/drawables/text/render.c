/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:32:35 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/11 19:57:59 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include <mlx.h>

void					mlx_text_render_txt(t_text *text, t_point2d offset, void *win)
{
	const t_window		*window = win;
	t_point2d			pos;
	size_t				text_width;

	pos = DDSUM(offset, text->pos);
	text_width = mlx_text_width(text->text);
	if (text->align == CENTER)
		pos.x -= text_width / 2;
	else if (text->align == RIGHT)
		pos.x -= text_width;
	mlx_string_put(window->mlx, window->ptr, pos.x, pos.y, text->color, text->text);
}
