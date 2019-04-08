/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:10:39 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 19:19:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/hooks.h"

t_keyboard_hooks		*mlx_init_keyhooks(void)
{
	t_keyboard_hooks	*hooks;

	if (!(hooks = malloc(sizeof(t_keyboard_hooks)
					+ (sizeof(t_keyboard_hook) * MLX_HOOK_INITIAL_CAPACITY))))
		return (NULL);
	hooks->capacity = MLX_HOOK_INITIAL_CAPACITY;
	hooks->add = mlx_add_keyhook;
	hooks->len = 0;
	return (hooks);
}

t_mouse_hooks			*mlx_init_mousehooks(void)
{
	t_mouse_hooks		*hooks;

	if (!(hooks = malloc(sizeof(t_mouse_hooks)
					+ (sizeof(t_mouse_hook) * MLX_HOOK_INITIAL_CAPACITY))))
		return (NULL);
	hooks->capacity = MLX_HOOK_INITIAL_CAPACITY;
	hooks->add = mlx_add_mousehook;
	hooks->len = 0;
	return (hooks);
}

t_motion_hooks			*mlx_init_motionhooks(void)
{
	t_motion_hooks		*hooks;

	if (!(hooks = malloc(sizeof(t_motion_hooks)
					+ (sizeof(t_motion_hook) * MLX_HOOK_INITIAL_CAPACITY))))
		return (NULL);
	hooks->capacity = MLX_HOOK_INITIAL_CAPACITY;
	hooks->add = mlx_add_motionhook;
	hooks->len = 0;
	return (hooks);
}
