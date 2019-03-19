/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:51:34 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/19 18:09:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"
#include "ft_printf.h"

static int					close_on_esc_handler(int key, void *s)
{
	(void)s;
	ft_printf("%d\n", key);
	return (0);
}

int							mlx_render_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->ptr);
	// if (window->close_on_esc)
	//	window->add_lkeyboard_hook(window, close_on_esc_handler);
	if (window->body)
		window->img = window->body->render(window->body, window, window->img);
	else
		return (1);
	return (0);
}
