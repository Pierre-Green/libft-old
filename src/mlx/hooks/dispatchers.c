/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatchers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:22:00 by pierre            #+#    #+#             */
/*   Updated: 2019/02/21 17:34:30 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/hooks.h"

static int					keyboard(int keycode, t_list *node, const t_hook_carry *carry)
{
	int						ret;
	int						(*f)(int, void *);

	ret = 0;
	while (node)
	{
		f = node->content;
		ret = f(keycode, carry->state);
		node = node->next;
	}
	return (ret);
}

int							keyboard_hooks_dispatcher(int keycode, void *p)
{
	const t_hook_carry		*carry = p;

	return (keyboard(keycode, carry->window->keyboard_hooks, carry));
}

int					lkeyboard_hooks_dispatcher(int keycode, void *p)
{
	const t_hook_carry		*carry = p;

	return (keyboard(keycode, carry->window->lkeyboard_hooks, carry));
}

int					mouse_hooks_dispatcher(int mouse, int x, int y, void *p)
{
	const t_hook_carry		*carry = p;
	t_list					*node;
	int						ret;
	int						(*f)(int, int, int, void *);

	ret = 0;
	node = carry->window->mouse_hooks;
	while (node)
	{
		f = node->content;
		ret = f(mouse, x, y, carry->state);
		node = node->next;
	}
	return (ret);
}
