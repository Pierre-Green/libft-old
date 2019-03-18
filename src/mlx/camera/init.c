/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:49:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 17:12:27 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/camera.h"

t_camera				*mlx_init_camera(t_vec3_d pos)
{
	t_camera			*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		return (NULL);
	camera->position = pos;
	camera->vec_front = ft_vec3_d_normalize(ft_vec3_d_minus(pos, ft_init0_vec3_d()));
	camera->vec_right = ft_vec3_d_normalize(ft_vec3_d_cross(ft_init3_vec3_d(0.0, 1.0, 0.0), camera->vec_front));
	camera->vec_up = ft_vec3_d_cross(camera->vec_front, camera->vec_right);
	camera->velocity = 0.05;
	return (camera);
}
