/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:07:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 17:16:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

void					mlx_camera_move_front(t_camera *self)
{
	self->position = ft_vec3_d_sum(self->position,
			ft_vec3_d_product1(self->vec_front, self->velocity));
}

void					mlx_camera_move_back(t_camera *self)
{
	self->position = ft_vec3_d_minus(self->position,
			ft_vec3_d_product1(self->vec_front, self->velocity));
}

void					mlx_camera_move_left(t_camera *self)
{
	self->position = ft_vec3_d_minus(self->position,
			ft_vec3_d_normalize(ft_vec3_d_product1(self->vec_right, self->velocity)));
}

void					mlx_camera_move_right(t_camera *self)
{
	self->position = ft_vec3_d_sum(self->position,
			ft_vec3_d_normalize(ft_vec3_d_product1(self->vec_right, self->velocity)));
}
