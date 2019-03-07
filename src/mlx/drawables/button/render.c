/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:11:32 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 15:42:34 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include <mlx.h>

typedef struct			s_dd
{
	void				*c;
	void				*p;
}						t_dd;

static void				onclick_middleware(int mouse, int x, int y, void *p)
{
	
}

void					mlx_button_render_txt(t_button *button, t_point2d offset, void *mlx_ptr, void *win)
{
	const t_window		*window = win;

	window->add_mouse_hook(window, onclick_middleware);
	mlx_string_put(mlx_ptr, window->ptr, offset.x + button->pos.x, offset.y + button->pos.y + button->dim.height, 0xFFFFFF, button->text);
}
