/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:39:18 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/11 19:07:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"

static void			window_events(t_window *window)
{
	mlx_key_hook(window->ptr, keyboard_hooks_dispatcher, window->carry);
	mlx_hook(window->ptr, 2, 1l<<0, lkeyboard_hooks_dispatcher, window->carry);
	mlx_mouse_hook(window->ptr, mouse_hooks_dispatcher, window->carry);
}

t_window			*ft_init_window(void *mlx_ptr, t_dim2d dims, char *title, void *s)
{
	t_window		*win;
	t_hook_carry	*carry;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	if (!(carry = malloc(sizeof(t_hook_carry *))))
		return (NULL);
	carry->window = win;
	carry->state = s;
	win->render = NULL;
	win->keyboard_hooks = NULL;
	win->mlx = mlx_ptr;
	win->add_keyboard_hook = add_keyboard_hook;
	win->lkeyboard_hooks = NULL;
	win->add_lkeyboard_hook = add_lkeyboard_hook;
	win->mouse_hooks = NULL;
	win->add_mouse_hook = add_mouse_hook;
	win->width = dims.width;
	win->should_render_every_frame = false;
	win->height = dims.height;
	win->carry = carry;
	win->ptr = mlx_new_window(mlx_ptr, dims.width, dims.height, title);
	window_events(win);
	return (win);
}
