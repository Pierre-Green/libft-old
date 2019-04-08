/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:52:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 17:23:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

static void				mlx_camera_update_rad(t_camera *self, double pitch, double yaw)
{
	const double		cos_pitch = cos(pitch);
	const double		sin_pitch = sin(pitch);
	const double		cos_yaw = cos(yaw);
	const double		sin_yaw = sin(yaw);

	self->vec_right = ft_init3_vec3_d(cos_yaw, 0, -sin_yaw);
	self->vec_up = ft_init3_vec3_d(sin_yaw * sin_pitch, cos_pitch, cos_yaw * sin_pitch);
	self->vec_front = ft_init3_vec3_d(sin_yaw * cos_pitch, -sin_pitch, cos_pitch * cos_yaw);
	self->view_mat.raw = (t_mat44_d_data){
		self->vec_right.x, self->vec_right.y, self->vec_right.z, 0,
		self->vec_up.x, self->vec_up.y, self->vec_up.z, 0,
		self->vec_front.x, self->vec_front.y, self->vec_front.z, 0,
		ft_vec3_d_product2(self->position, self->vec_right),
		ft_vec3_d_product2(self->position, self->vec_up),
		ft_vec3_d_product2(self->position, self->vec_front), 1
	};
}

void					mlx_camera_update_view_mat(t_camera *self)
{
	self->view_mat = ft_multiply_matrix44_d(
			ft_rotation_matrix44_d(self->rotation.x, self->rotation.y, self->rotation.z),
			ft_translation_matrix44_d(self->position.x, self->position.y, self->position.z));
	self->view_mat = ft_multiply_matrix44_d(self->view_mat, ft_perspective_matrix44_d(70, 1, 100));
}
