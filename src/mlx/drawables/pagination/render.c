/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:32:25 by pierre            #+#    #+#             */
/*   Updated: 2019/03/13 17:27:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"

static void					render_txt_node(t_drawables *node, t_point2d offset, t_window *window)
{
	t_drwble			obj;

	obj = node->drawable->drawable;
	if (node->drawable->type == CONTAINER)
		obj.container->render_txt(obj.container, offset, window);
	if (node->drawable->type == BUTTON)
		obj.button->render_txt(obj.button, offset, window);
	node = node->next;
}

static void				pagination_render_txt_bot(t_pagination *self, t_point2d p_offset, t_window *window)
{
	t_point2d			offset;

	offset.y = p_offset.y + self->zone.dim.height - MLX_PAGINATION_BOT_SIZE;
	offset.x = p_offset.x;
	self->prev->render_txt(self->prev, offset, window);
	self->next->render_txt(self->next, offset, window);
}

void					mlx_pagination_render_txt(t_pagination *pagination, t_point2d offset, void *win)
{
	const t_window		*window = win;
	const t_drawables	*node = pagination->items;
	t_zone2d			gride;
	t_point2d			next_offset;
	size_t				current;

	offset = DDSUM(offset, pagination->zone.pos);
	gride = ft_zone2d_from_pdim(POS(0, 0), pagination->gride);
	current = 0;
	while (current++ < pagination->page * (pagination->gride.width * pagination->gride.height))
		node = node->next;
	while (gride.pos.y < (int)gride.dim.height && node)
	{
		gride.pos.x = 0;
		while (gride.pos.x < (int)gride.dim.width && node)
		{
			next_offset = mlx_pagination_offset(pagination, offset, gride, true);
			render_txt_node((t_drawables *)node, next_offset, (t_window *)window);
			node = node->next;
			gride.pos.x++;
		}
		gride.pos.y++;
	}
	pagination_render_txt_bot(pagination, offset, (t_window *)window);
}
