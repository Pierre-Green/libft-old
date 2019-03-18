/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:39:18 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 22:08:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"

static void			window_events(t_window *win)
{
	mlx_key_hook(win->ptr, keyboard_hooks_dispatcher, win->carry);
	mlx_hook(win->ptr, 2, 1l << 0, lkeyboard_hooks_dispatcher, win->carry);
	mlx_mouse_hook(win->ptr, mouse_hooks_dispatcher, win->carry);
}

t_window			*ft_init_window(void *mlx_ptr, t_dim2d dims, char *title,
		void *s)
{
	t_window		*win;
	t_hook_carry	*carry;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	if (!(carry = malloc(sizeof(t_hook_carry *))))
		return (NULL);
	carry->window = win;
	carry->state = s;
	win->render = mlx_render_window;
	win->body = NULL;
	win->keyboard_hooks = NULL;
	win->mlx = mlx_ptr;
	win->add_keyboard_hook = add_keyboard_hook;
	win->lkeyboard_hooks = NULL;
	win->add_lkeyboard_hook = add_lkeyboard_hook;
	win->mouse_hooks = NULL;
	win->add_mouse_hook = add_mouse_hook;
	win->img = NULL;
	win->width = dims.width;
	win->should_render_every_frame = FALSE;
	win->height = dims.height;
	win->carry = carry;
	win->ptr = mlx_new_window(mlx_ptr, dims.width, dims.height, title);
	window_events(win);
	return (win);
}
