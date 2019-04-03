/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:08:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/03 18:42:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_rotate(t_camera *self, t_camera_rotations rotation)
{
	if (rotation == PITCH_UP)
		self->pitch -= self->rotat_velocity;
	else if (rotation == PITCH_DOWN)
		self->pitch += self->rotat_velocity;
	else if (rotation == YAW_LEFT)
		self->yaw -= self->rotat_velocity;
	else if (rotation == YAW_RIGHT)
		self->yaw += self->rotat_velocity;
	if (self->pitch > 89)
		self->pitch = 89;
	else if (self->pitch < -89)
		self->pitch = -89;
	if (self->yaw < 1)
		self->yaw = 1;
	else if (self->yaw > 359)
		self->yaw = 359;
	self->update(self);
}
