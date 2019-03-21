/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_dispatchers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:29:06 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 20:54:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"
#include "ft_printf.h"

int							keyboard_hooks_dispatcher(int keycode, void *p)
{
	const t_hook_carry		*carry = p;
	t_keyboard_hooks		*hooks;
	size_t					current;

	ft_printf("Key: %d\n", keycode);
	hooks = carry->window->keyboard_hooks;
	current = 0;
	while (current < hooks->len)
	{
		if (keycode == hooks->hooks[current].key)
			hooks->hooks[current].onpress(carry->state);
		current++;
	}
	hooks->len = 0;
	carry->window->render(carry->window);
	return (0);
}

int							mouse_hooks_dispatcher(int mouse, int x, int y,
		void *p_carry)
{
	const t_hook_carry		*carry = p_carry;
	t_mouse_hooks			*hooks;
	t_mouse_hook			hook;
	size_t					current;

	hooks = carry->window->mouse_hooks;
	current = 0;
	while (current < hooks->len)
	{
		hook = hooks->hooks[current];
		if (ft_is_point_in_zone2d(hook.zone, (t_point2d){ x, y }) 
				&& hook.onclick)
			hook.onclick(mouse, hook.id,
					(hook.s ? hook.s : carry->state));
		current++;
	}
	hooks->len = 0;
	carry->window->render(carry->window);
	return (0);
}
