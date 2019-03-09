/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:32:25 by pierre            #+#    #+#             */
/*   Updated: 2019/03/10 00:11:06 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"

static void					render_txt_node(t_drawables *node, t_point2d offset, void *mlx_ptr, t_window *window)
{
	t_drwble			obj;

	obj = node->drawable->drawable;
	if (node->drawable->type == CONTAINER)
		obj.container->render_txt(obj.container, offset, mlx_ptr, window->ptr);
	if (node->drawable->type == BUTTON)
		obj.button->render_txt(obj.button, offset, mlx_ptr, window->ptr);
	node = node->next;
}

void					mlx_pagination_render_txt(t_pagination *pagination, t_point2d offset, void *mlx_ptr, void *win)
{
	const t_window		*window = win;
	const t_drawables	*node = pagination->items;
	t_zone2d			gride;
	t_point2d			next_offset;

	offset = DDSUM(offset, pagination->zone.pos);
	gride = ft_zone2d_from_pdim(POS(0, 0), mlx_pagination_gride_dims(pagination));
	while (gride.pos.y < (int)gride.dim.height)
	{
		gride.pos.x = 0;
		while (gride.pos.x < (int)gride.dim.width)
		{
			next_offset = mlx_pagination_offset(pagination, offset, gride, true);
			render_txt_node((t_drawables *)node, next_offset, mlx_ptr, (t_window *)window);
			node = node->next;
			gride.pos.x++;
		}
		gride.pos.y++;
	}
}
