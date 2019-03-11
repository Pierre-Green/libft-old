/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:39:18 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/11 18:38:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"


t_window			*ft_init_window()
{
	t_window		*win;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	win->render = NULL;
	win->keyboard_hooks = NULL;
	win->add_keyboard_hook = add_keyboard_hook;
	win->lkeyboard_hooks = NULL;
	win->add_lkeyboard_hook = add_lkeyboard_hook;
	win->mouse_hooks = NULL;
	win->add_mouse_hook = add_mouse_hook;
	win->width = DEFAULT_WIDTH;
	win->should_render_every_frame = false;
	win->height = DEFAULT_HEIGHT;
	win->ptr = NULL;
	return (win);
}
