/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:08:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/01 18:37:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_mouse(t_camera *self, double xoffset, double yoffset)
{
	self->yaw += xoffset * self->mouse_velocity;
	self->pitch += yoffset * self->mouse_velocity;
	if (self->yaw > 89)
		self->yaw = 89;
	if (self->pitch > 89)
		self->pitch = 89;
	mlx_camera_update_vecs(self);
}
