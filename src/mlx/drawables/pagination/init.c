/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:43:14 by pierre            #+#    #+#             */
/*   Updated: 2019/03/13 19:58:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_printf.h"


static void				onclick(int mouse, int action, void *s)
{
	t_pagination		*pagination;
	
	pagination = s;
	(void)mouse;
	ft_printf("Action : %d\n", action);
	if (action == MLX_PAGINATION_ACTION_PREV && pagination->page > 0)
		pagination->page--;
	if (action == MLX_PAGINATION_ACTION_NEXT && pagination->page < pagination->items_count / (pagination->gride.height * pagination->gride.width))
		pagination->page++;
}

static t_button			*pagination_prev(t_pagination *self)
{
	t_button			*prev;
	t_point2d			pos;

	pos.y = 0;
	pos.x = 100;
	if (!(prev = mlx_init_button(pos, DIM(self->zone.dim.width / 4,
		MLX_PAGINATION_BOT_SIZE - 20), 0x724F5B, "Previous",
		MLX_PAGINATION_ACTION_PREV)))
		return (NULL);
	prev->s = self;
	prev->onclick = onclick;
	return (prev);
}

static t_button			*pagination_next(t_pagination *self)
{
	t_button			*next;
	t_point2d			pos;

	pos.y = 0;
	pos.x = 300;
	if (!(next = mlx_init_button(pos, DIM(self->zone.dim.width / 4,
		MLX_PAGINATION_BOT_SIZE - 20), 0x724F5B, "Next",
		MLX_PAGINATION_ACTION_NEXT)))
		return (NULL);
	next->s = self;
	next->onclick = onclick;
	return (next);
}

t_pagination			*mlx_init_pagination(t_zone2d zone, t_dim2d item_dim, t_margin item_margin)
{
	t_pagination		*pagination;
	size_t				curr;

	if (!(pagination = malloc(sizeof(t_pagination))))
		return (NULL);
	pagination->zone = zone;
	pagination->items_dim = item_dim;
	curr = 0;
	while (curr++ < 4)
		pagination->items_margin[curr - 1] = item_margin[curr - 1];
	pagination->items_count = 0;
	pagination->items = NULL;
	pagination->page = 0;
	pagination->render_txt = mlx_pagination_render_txt;
	pagination->add_child = mlx_pagination_add_item;
	pagination->image = mlx_pagination_image;
	pagination->gride = mlx_pagination_gride_dims(pagination);
	if (!(pagination->prev = pagination_prev(pagination)))
		return (NULL);
	if (!(pagination->next = pagination_next(pagination)))
		return (NULL);
	return (pagination);
}
