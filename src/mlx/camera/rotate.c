/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:08:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 17:39:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

static void				update_vecs(t_camera *self)
{
	const double		sin_yaw = sin(ft_degrees_to_radian(self->rotation.y));
	const double		cos_yaw = cos(ft_degrees_to_radian(self->rotation.y));
	const double		sin_pitch = sin(ft_degrees_to_radian(self->rotation.x));
	const double		cos_pitch = cos(ft_degrees_to_radian(self->rotation.x));

	self->vec_right = ft_init3_vec3_d(cos_yaw, 0, -sin_yaw);
	self->vec_up = ft_init3_vec3_d(sin_yaw * sin_pitch, cos_pitch, cos_yaw * sin_pitch);
	self->vec_front = ft_init3_vec3_d(sin_yaw * cos_pitch, -sin_pitch, cos_pitch * cos_yaw);
}

void					mlx_camera_rotate(t_camera *self, t_camera_rotations rotation)
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
		self->rotation.y = 359;
	self->update(self);
}
