/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:17:11 by pierre            #+#    #+#             */
/*   Updated: 2019/03/21 16:11:27 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_mlx/window.h"

t_keyboard_hooks		*add_keyboard_hook(t_window *window, int keycode,
		void (*f)(void *), void *s)
{
	t_keyboard_hooks	*hooks;

	if (!window->keyboard_hooks)
	{
		if (!(window->keyboard_hooks = malloc(sizeof(t_keyboard_hooks))))
			return (NULL);
		window->keyboard_hooks->next = NULL;
		window->keyboard_hooks->carry = s;
		window->keyboard_hooks->onpress = f;;
		window->keyboard_hooks->keycode = keycode;
	}
	else
	{
		hooks = window->keyboard_hooks;
		while (hooks->next)
			hooks = hooks->next;
		hooks->next->next = NULL;
		hooks->next->carry = s;
		hooks->next->onpress = f;
		hooks->next->keycode = keycode;
	}
	return (window->keyboard_hooks);
}

t_mouse_hooks			*add_mouse_hook(t_window *window, int id, t_zone2d zone,
		void (*f)(t_mouse, int, void *), void *s)
{
	t_mouse_hooks		*hooks;

	if (!window->mouse_hooks)
	{
		if (!(window->mouse_hooks = malloc(sizeof(t_mouse_hooks))))
			return (NULL);
		window->mouse_hooks->zone = zone;
		window->mouse_hooks->onclick = f;
		window->mouse_hooks->carry = s;
		window->mouse_hooks->uuid = id;
		window->mouse_hooks->next = NULL;
	}
	else
	{
		hooks = window->mouse_hooks;
		while (hooks->next)
			hooks = hooks->next;
		if (!(hooks->next = malloc(sizeof(t_mouse_hooks))))
			return (NULL);
		hooks->next->zone = zone;
		hooks->next->onclick = f;
		hooks->next->uuid = id;
		hooks->next->carry = s;
		hooks->next->next = NULL;
	}
	return (window->mouse_hooks);
}
