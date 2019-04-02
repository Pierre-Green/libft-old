/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:49:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/02 20:06:02 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

t_camera				*mlx_init_camera(t_vec3_d pos)
{
	t_camera			*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (NULL);
	camera->position = pos;
	camera->world_up = ft_init3_vec3_d(0, 1, 0);
	camera->yaw = CAM_DEFAULT_YAW;
	camera->pitch = CAM_DEFAULT_PITCH;
	camera->vec_up = ft_vec3_d_cross(camera->vec_front, camera->vec_right);
	camera->vec_right = ft_vec3_d_normalize(ft_vec3_d_cross(camera->world_up, camera->vec_front));
	camera->vec_front = ft_vec3_d_normalize(ft_vec3_d_minus(pos, ft_init0_vec3_d()));
	camera->velocity = CAM_DEFAULT_VELOCITY;
	camera->rotation_velocity = CAM_DEFAULT_ROTATION_VELOCITY;
	camera->update = mlx_camera_update_view_mat;
	return (camera);
}
