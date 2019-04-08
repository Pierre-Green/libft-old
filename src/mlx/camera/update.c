/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:52:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 19:16:33 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_update_view_mat(t_camera *self)
{
	self->view_mat = ft_multiply_matrix44_d(
			ft_rotation_matrix44_d(self->rotation.x, self->rotation.y,
				self->rotation.z),
			ft_translation_matrix44_d(self->position.x, self->position.y,
				self->position.z));
	self->view_mat = ft_multiply_matrix44_d(self->view_mat,
			ft_perspective_matrix44_d(70, 1, 100));
}
