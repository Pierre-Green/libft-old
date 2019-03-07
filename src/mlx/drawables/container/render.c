/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 02:48:40 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 03:24:13 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include <mlx.h>

static void					mlx_container_text_drawer(t_container *container, void *mlx_ptr, t_window *win)
{
	t_drawables				*node;
	t_text					*txt;

	node = container->childs;
	while (node)
	{
		if (node->drawable->type == CONTAINER)
			mlx_container_text_drawer(node->drawable->drawable, mlx_ptr, win);
		if (node->drawable->type == TEXT)
		{
			txt = (t_text *)node->drawable->drawable;
			mlx_string_put(mlx_ptr, win->ptr, txt->pos.x, txt->pos.y, txt->color, txt->text);
		}
		node = node->next;
	}
}

t_image_carry				*mlx_container_render(t_container *container, void *mlx_ptr, void *win, t_image_carry *old)
{
	const t_window			*window = win;
	void					*tmptr;
	char					*tmpch;
	int						params[3];

	if (!old)
	{
		tmptr = mlx_new_image(mlx_ptr, window->width, window->height);
		tmpch = mlx_get_data_addr(tmptr, &params[0], &params[1], &params[2]);
		old = ft_image_carry_from(tmptr, &tmpch, params[0], params[1], params[2]);
	}
	*old->data = container->image(container, POS(0, 0), old);
	mlx_put_image_to_window(mlx_ptr, window->ptr, old->img_ptr, 0, 0);
	mlx_container_text_drawer(container, mlx_ptr, (t_window *)window);
	return (old);
}
