/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 20:14:06 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 20:03:15 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/hooks.h"

void				mlx_copy_keyhooks(t_keyboard_hooks *dest,
		t_keyboard_hooks *src)
{
	size_t			current;
	t_keyboard_hook	hook;

	current = 0;
	while (current < src->len)
	{
		hook = src->hooks[current];
		dest->add(dest, hook.key, hook.onpress, hook.s);
		current++;
	}
}

void				mlx_copy_mousehooks(t_mouse_hooks *dest, t_mouse_hooks *src)
{
	size_t			current;
	t_mouse_hook	hook;

	current = 0;
	while (current < src->len)
	{
		hook = src->hooks[current];
		dest->add(dest, hook.id, hook.zone, hook.onclick, hook.s);
		current++;
	}
}

void				mlx_copy_mousehooks_offset(t_mouse_hooks *dest,
		t_mouse_hooks *src, t_point2d offset)
{
	size_t			current;
	t_mouse_hook	hook;

	current = 0;
	while (current < src->len)
	{
		hook = src->hooks[current];
		dest->add(dest, hook.id,
				ft_zone2d_from_pdim(DDSUM(hook.zone.pos, offset),
					hook.zone.dim), hook.onclick, hook.s);
		current++;
	}
}

void				mlx_copy_motionhooks(t_motion_hooks *dest, t_motion_hooks *src)
{
	size_t			current;
	t_motion_hook	hook;

	current = 0;
	while (current < src->len)
	{
		hook = src->hooks[current];
		dest->add(dest, hook.zone, hook.onmotion, hook.s);
		current++;
	}
}
