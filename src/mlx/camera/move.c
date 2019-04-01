/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:07:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/01 18:37:53 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_move(t_camera *self, t_camera_movement movement)
{
	if (movement == FORWARD)
		self->position = ft_vec3_d_minus(self->position,
			ft_vec3_d_product1(self->vec_front, self->velocity));
	else if (movement == BACKWARD)
		self->position = ft_vec3_d_sum(self->position,
			ft_vec3_d_product1(self->vec_front, self->velocity));
	else if (movement == RIGHTWARD)
		self->position = ft_vec3_d_minus(self->position,
			ft_vec3_d_normalize(ft_vec3_d_product1(self->vec_right, self->velocity)));
	else if (movement == LEFTWARD)
		self->position = ft_vec3_d_sum(self->position,
			ft_vec3_d_normalize(ft_vec3_d_product1(self->vec_right, self->velocity)));
}
