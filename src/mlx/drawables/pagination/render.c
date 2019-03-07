/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 20:32:25 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 20:58:16 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"

void					mlx_pagination_render_txt(t_pagination *pagination, t_point2d offset, void *mlx_ptr, void *win)
{
	const t_window		*window = win;
	const t_drawables	*node = pagination->items;
	t_drwble			obj;

	while (node)
	{
		obj = node->drawable->drawable;
		if (node->drawable->type == CONTAINER)
			obj.container->render_txt(obj.container, offset, mlx_ptr, window->ptr);
		node = node->next;
	}
}
