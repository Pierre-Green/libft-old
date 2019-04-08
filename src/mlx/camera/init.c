/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:49:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 17:46:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

t_camera				*mlx_init_camera(t_vec3_d pos)
{
	t_camera			*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (NULL);
	camera->position = pos;
	camera->rotation.y = CAM_DEFAULT_YAW;
	camera->rotation.x = CAM_DEFAULT_PITCH;
	camera->trans_velocity = CAM_DEFAULT_TRANSLATION_VELOCITY;
	camera->mode = PERSPECTIVE;
	camera->rotat_velocity = CAM_DEFAULT_ROTATION_VELOCITY;
	camera->update = mlx_camera_update_view_mat;
	return (camera);
}
