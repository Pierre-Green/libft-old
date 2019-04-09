/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:45:24 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 16:52:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"

static void				render_txt_node(t_drawable drawable, t_point2d offset,
		t_window *window)
{
	t_drwble			obj;

	obj = drawable.drawable;
	if (drawable.type == CONTAINER)
		obj.container->render_txt(obj.container, offset, window);
	if (drawable.type == BUTTON)
		obj.button->render_txt(obj.button, offset, window);
}

static void				pagination_render_txt_bot(t_pagination *self,
		t_point2d p_offset, t_window *window)
{
	t_point2d			offset;

	offset.y = p_offset.y + self->zone.dim.height - MLX_PAGINATION_BOT_SIZE;
	offset.x = p_offset.x;
	self->prev->render_txt(self->prev, offset, window);
	self->next->render_txt(self->next, offset, window);
}

void					mlx_pagination_render_txt(t_pagination *pagination,
		t_point2d offset, void *win)
{
	const t_window		*window = win;
	t_zone2d			gride;
	t_point2d			next_offset;
	size_t				current;

	offset = DDSUM(offset, pagination->zone.pos);
	gride = ft_zone2d_from_pdim(POS(0, 0), pagination->gride);
	current = pagination->page * (pagination->gride.width * pagination->gride.height);
	while (gride.pos.y < (int)gride.dim.height && current < pagination->items->len)
	{
		gride.pos.x = 0;
		while (gride.pos.x < (int)gride.dim.width && current < pagination->items->len)
		{
			next_offset = mlx_pagination_offset(pagination, offset,
					gride, TRUE);
			render_txt_node(pagination->items->drawables[current], next_offset,
					(t_window *)window);
			current++;
			gride.pos.x++;
		}
		gride.pos.y++;
	}
	pagination_render_txt_bot(pagination, offset, (t_window *)window);
}
