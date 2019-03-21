/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:26:17 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 17:13:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"

void					mlx_canvas_register_events(t_canvas *self, t_point2d offset,
		void *p_win)
{
	const t_window		*win = p_win;
	t_keyboard_hooks	*key_hooks;

	(void)offset;
	key_hooks = win->keyboard_hooks;
	while (key_hooks->next)
		key_hooks = key_hooks->next;
	key_hooks->next = self->keyboard_hooks;
}
