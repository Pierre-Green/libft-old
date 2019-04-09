/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:14:51 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 17:11:24 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mem.h"

void					mlx_kill_container(t_container **container,
		void *mlx_ptr)
{
	t_drawable			drawable;
	size_t				current;

	current = 0;
	while (current < (*container)->childs->len)
	{
		drawable = (*container)->childs->drawables[current];
		if (drawable.type == CONTAINER)
			mlx_kill_container(&drawable.drawable.container, mlx_ptr);
		else if (drawable.type == TEXT)
			mlx_kill_text(&drawable.drawable.text);
		else if (drawable.type == BUTTON)
			mlx_kill_button(&drawable.drawable.button);
		else if (drawable.type == PAGINATION)
			mlx_kill_pagination(&drawable.drawable.pagination);
		else if (drawable.type == CANVAS)
			mlx_kill_canvas(&drawable.drawable.canvas, mlx_ptr);
		current++;
	}
	ft_memdel((void **)container);
}
