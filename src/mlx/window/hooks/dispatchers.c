/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatchers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:29:06 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/19 18:04:43 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"
#include "ft_printf.h"
#include "ft_mem.h"

static int					keyboard(int key, t_list *node,
		t_hook_carry *carry)
{
	int						ret;
	int						(*f)(int, void *);

	ret = 0;
	while (node)
	{
		f = node->content;
		ret = f(key, carry);
		node = node->next;
	}
	carry->window->lkeyboard_hooks = NULL;
	carry->window->keyboard_hooks = NULL;
	carry->window->render(carry->window);
	return (ret);
}

int							keyboard_hooks_dispatcher(int keycode, void *p)
{
	const t_hook_carry		*carry = p;

	return (keyboard(keycode, carry->window->keyboard_hooks, (t_hook_carry *)carry));
}

int							lkeyboard_hooks_dispatcher(int keycode, void *p)
{
	const t_hook_carry		*carry = p;

	return (keyboard(keycode, carry->window->lkeyboard_hooks, (t_hook_carry *)carry));
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
