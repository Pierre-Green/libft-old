/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:26:35 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 21:41:06 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"

void						mlx_kill_window(t_window *self)
{
	mlx_kill_image_carry(self->img, self->mlx);
	mlx_kill_keyhooks(self->keyboard_hooks);
	mlx_kill_mousehooks(self->mouse_hooks);
}
