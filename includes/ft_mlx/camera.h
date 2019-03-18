/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:30:54 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 17:12:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CAMERA_H
# define FT_MLX_CAMERA_H
# include <stdlib.h>
# include "ft_math/vec.h"
# include "ft_math/matrix.h"

typedef struct			s_camera
{
	t_vec3_d			position;
	t_vec3_d			vec_up;
	t_vec3_d			vec_right;
	t_vec3_d			vec_front;
	double				velocity;
	t_matrix44_d		view_mat;
}						t_camera;

t_camera				*mlx_init_camera(t_vec3_d pos);

void					mlx_camera_update_view_mat(t_camera *self);

void					mlx_camera_move_front(t_camera *self);

void					mlx_camera_move_back(t_camera *self);

void					mlx_camera_move_left(t_camera *self);

void					mlx_camera_move_right(t_camera *self);

#endif
