/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:11:32 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 16:38:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include <mlx.h>

void					mlx_button_render_txt(t_button *button, t_point2d offset, void *mlx_ptr, void *win)
{
	t_window			*window;

	window = win;
	window->add_mouse_hook(window, ft_zone2d_from_pdim(DDSUM(offset, button->pos), button->dim), button->onclick);
	mlx_string_put(mlx_ptr, window->ptr, offset.x + button->pos.x, offset.y + button->pos.y + button->dim.height, 0xFFFFFF, button->text);
}
