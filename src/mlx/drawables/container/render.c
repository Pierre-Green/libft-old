/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 02:48:40 by pierre            #+#    #+#             */
/*   Updated: 2019/03/08 01:52:02 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include <mlx.h>

void						mlx_container_render_txt(t_container *container, t_point2d offset, void *mlx_ptr, void *win)
{
	const t_window			*window = win;
	t_drawables				*node;
	t_drwble				obj;

	node = container->childs;
	while (node)
	{
		obj = node->drawable->drawable;
		if (node->drawable->type == CONTAINER)
			mlx_container_render_txt(obj.container, DDSUM(offset, obj.container->pos), mlx_ptr, win);
		if (node->drawable->type == TEXT)
			mlx_string_put(mlx_ptr, window->ptr, obj.text->pos.x, obj.text->pos.y, obj.text->color, obj.text->text);
		if (node->drawable->type == BUTTON)
			obj.button->render_txt(obj.button, offset, mlx_ptr, win);
		if (node->drawable->type == PAGINATION)
			obj.pagination->render_txt(obj.pagination, offset, mlx_ptr, win);
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
	container->render_txt(container, POS(0, 0), mlx_ptr, win);
	return (old);
}
