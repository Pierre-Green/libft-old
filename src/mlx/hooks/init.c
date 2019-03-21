/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:10:39 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 18:14:38 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/hooks.h"

t_keyboard_hooks		*mlx_init_keyhooks()
{
	t_keyboard_hooks	*hooks;

	if (!(hooks = malloc(sizeof(t_keyboard_hooks)
					+ (sizeof(t_keyboard_hook) * MLX_HOOK_INITIAL_CAPACITY))))
		return (NULL);
	hooks->capacity = MLX_HOOK_INITIAL_CAPACITY;
	hooks->len = 0;
	return (hooks);
}
