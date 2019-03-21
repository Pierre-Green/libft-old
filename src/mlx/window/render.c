/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:51:34 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 21:42:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"
#include "ft_printf.h"

static void					close_on_esc_handler(void *s)
{
	t_window				*win;

	win = s;
	win->kill(win);
}

int							mlx_render_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->ptr);
	if (window->close_on_esc)
		window->keyboard_hooks->add(window->keyboard_hooks, 53,
				close_on_esc_handler, window);
	if (window->body)
		window->img = window->body->render(window->body, window, window->img);
	else
		return (1);
	return (0);
}
