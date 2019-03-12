/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:11:32 by pierre            #+#    #+#             */
/*   Updated: 2019/03/12 14:45:57 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include "ft_str.h"
#include <mlx.h>

void					mlx_button_render_txt(t_button *button, t_point2d offset, void *win)
{
	t_window			*window;
	t_point2d			next_offset;

	next_offset = DDSUM(offset, button->pos);
	next_offset.y += button->dim.height / 2;
	next_offset.x += button->dim.width / 2;
	window = win;
	window->add_mouse_hook(window, button->uuid, ft_zone2d_from_pdim(DDSUM(offset, button->pos), button->dim), button->onclick);
	button->text->render_txt(button->text, next_offset, win);
}
