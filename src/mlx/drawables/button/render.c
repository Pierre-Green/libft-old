/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:33:27 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/15 14:02:56 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include "ft_str.h"
#include <mlx.h>

void					mlx_button_render_txt(t_button *button,
		t_point2d offset, void *win)
{
	t_window			*window;
	t_point2d			next_offset;

	next_offset = DDSUM(offset, button->pos);
	next_offset.y += button->dim.height / 2;
	next_offset.x += button->dim.width / 2;
	window = win;
	if (button->enabled)
		window->add_mouse_hook(window, button->uuid,
			ft_zone2d_from_pdim(DDSUM(offset, button->pos), button->dim),
			button->onclick, button->s);
	else
		button->text->color = 0x000000;
	button->text->render_txt(button->text, next_offset, win);
}
