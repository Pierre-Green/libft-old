/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:27:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 19:59:25 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/hooks.h"

void				mlx_add_keyhook(t_keyboard_hooks *hooks, int key,
		t_onpress onpress, void *s)
{
	hooks->hooks[hooks->len] = (t_keyboard_hook){ key, onpress, s };
	hooks->len++;
}

void				mlx_add_mousehook(t_mouse_hooks *hooks, int id,
		t_zone2d zone, t_onclick onclick, void *s)
{
	hooks->hooks[hooks->len] = (t_mouse_hook){ zone, id, onclick, s };
	hooks->len++;
}
