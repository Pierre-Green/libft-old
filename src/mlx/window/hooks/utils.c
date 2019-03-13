/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:17:11 by pierre            #+#    #+#             */
/*   Updated: 2019/03/13 16:43:00 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_mlx/window.h"

void				add_keyboard_hook(t_window *window, int (*f)(int, void *))
{
	if (window->keyboard_hooks)
		ft_lstadd(&window->keyboard_hooks, ft_lstnew(f, sizeof(f)));
	else
		window->keyboard_hooks = ft_lstnew(f, sizeof(f));
}

void				add_lkeyboard_hook(t_window *window, int (*f)(int, void *))
{
	if (window->lkeyboard_hooks)
		ft_lstadd(&window->lkeyboard_hooks, ft_lstnew(f, sizeof(f)));
	else
		window->lkeyboard_hooks = ft_lstnew(f, sizeof(f));
}

t_mouse_hooks		*add_mouse_hook(t_window *window, int id, t_zone2d zone, void (*f)(t_mouse, int, void *), void *s)
{
	t_mouse_hooks	*hooks;

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
