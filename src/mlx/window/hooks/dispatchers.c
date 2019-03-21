/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatchers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:29:06 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 16:20:43 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"
#include "ft_printf.h"
#include "ft_mem.h"

int							keyboard_hooks_dispatcher(int keycode, void *p)
{
	const t_hook_carry		*carry = p;
	t_keyboard_hooks		*node;

	node = carry->window->keyboard_hooks;
	while (node)
	{
		if (keycode == node->keycode)
			node->onpress(carry->state);
		node = node->next;
	}
	carry->window->keyboard_hooks = NULL;
	carry->window->render(carry->window);
	return (0);
}

int							mouse_hooks_dispatcher(int mouse, int x, int y,
		void *p_carry)
{
	const t_hook_carry		*carry = p_carry;
	t_mouse_hooks			*node;

	node = carry->window->mouse_hooks;
	while (node)
	{
		if (ft_is_point_in_zone2d(node->zone, (t_point2d){ x, y }) && node->onclick)
			node->onclick(mouse, node->uuid,
					(node->carry ? node->carry : carry->state));
		node = node->next;
	}
	carry->window->mouse_hooks = NULL;
	carry->window->render(carry->window);
	return (0);
}
