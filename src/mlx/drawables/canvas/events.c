/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:26:17 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 21:12:13 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"
#include "ft_mlx/window.h"

void					mlx_canvas_register_events(t_canvas *self,
		t_point2d p_offset, void *p_win)
{
	const t_window		*win = p_win;
	const t_point2d		offset = DDSUM(p_offset, self->zone.pos);

	mlx_copy_keyhooks(win->keyboard_hooks, self->keyboard_hooks);
	self->keyboard_hooks->len = 0;
	mlx_copy_mousehooks_offset(win->mouse_hooks, self->mouse_hooks, offset);
	self->mouse_hooks->len = 0;
}
