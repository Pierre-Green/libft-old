/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:07:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 19:33:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_move(t_camera *self,
		t_camera_movement movement)
{
	const double		cos_pitch = cos(ft_degrees_to_radian(self->rotation.x));
	const double		sin_pitch = sin(ft_degrees_to_radian(self->rotation.x));
	const double		cos_yaw = cos(ft_degrees_to_radian(self->rotation.y));
	const double		sin_yaw = sin(ft_degrees_to_radian(self->rotation.y));
	t_vec3_d			direction;

	if (movement == FORWARD || movement == BACKWARD)
	{
		direction = (t_vec3_d){ sin_yaw,
			-sin_pitch, -cos_yaw };
		if (movement == FORWARD)
			direction = (t_vec3_d){ -direction.x, -direction.y, -direction.z};
	}
	else
	{
		direction = (t_vec3_d){ cos_yaw, 0, sin_yaw };
		if (movement == RIGHTWARD)
			direction = (t_vec3_d){ -direction.x, -direction.y, -direction.z};
	}
	self->position = ft_vec3_d_sum(self->position,
			ft_vec3_d_product1(direction, self->trans_velocity));
	self->update(self);
}
