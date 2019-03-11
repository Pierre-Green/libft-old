/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:11:32 by pierre            #+#    #+#             */
/*   Updated: 2019/03/11 19:50:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include "ft_str.h"
#include <mlx.h>

void					mlx_button_render_txt(t_button *button, t_point2d offset, void *win)
{
	t_window			*window;
	size_t				text_width;

	window = win;
	text_width = mlx_text_width(button->text);
	window->add_mouse_hook(window, button->uuid, ft_zone2d_from_pdim(DDSUM(offset, button->pos), button->dim), button->onclick);
	mlx_string_put(window->mlx, window->ptr, (offset.x + button->pos.x + button->dim.width / 2) - text_width / 2, offset.y + button->pos.y + button->dim.height / 2, 0xFFFFFF, button->text);
}
