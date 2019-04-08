/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:08:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 19:17:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_rotate(t_camera *self,
		t_camera_rotations rotation)
{
	if (rotation == PITCH_UP)
		self->rotation.x += self->rotat_velocity;
	else if (rotation == PITCH_DOWN)
		self->rotation.x -= self->rotat_velocity;
	else if (rotation == YAW_LEFT)
		self->rotation.y -= self->rotat_velocity;
	else if (rotation == YAW_RIGHT)
		self->rotation.y += self->rotat_velocity;
	if (self->rotation.x > 89)
		self->rotation.x = 89;
	else if (self->rotation.x < -89)
		self->rotation.x = -89;
	if (self->rotation.y < 1)
		self->rotation.y = 1;
	else if (self->rotation.y > 359)
		self->rotation.y = 1;
	self->update(self);
}
