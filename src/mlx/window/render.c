/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:51:34 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:30:45 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"

int							mlx_render_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->ptr);
	if (window->body)
		window->img = window->body->render(window->body, window->ptr,
				window, window->img);
	return (0);
}
