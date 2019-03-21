/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:28:57 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 21:32:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/hooks.h"
#include "ft_mem.h"

void				mlx_kill_keyhooks(t_keyboard_hooks *hooks)
{
	ft_memdel((void **)&hooks);
}

void				mlx_kill_mousehooks(t_mouse_hooks *hooks)
{
	ft_memdel((void **)&hooks);
}
