/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:30:54 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/02 20:05:24 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CAMERA_H
# define FT_MLX_CAMERA_H
# include <stdlib.h>
# include <math.h>
# include "ft_math/vec.h"
# include "ft_math/matrix.h"
# include "ft_utils.h"

# define CAM_DEFAULT_YAW -90.0
# define CAM_DEFAULT_PITCH 0.0
# define CAM_DEFAULT_VELOCITY 2
# define CAM_DEFAULT_ROTATION_VELOCITY 0.1

typedef enum			e_camera_movement
{
	FORWARD,
	BACKWARD,
	LEFTWARD,
	RIGHTWARD
}						t_camera_movement;

typedef enum			e_camera_rotations
{
	PITCH_UP,
	PITCH_DOWN,
	YAW_LEFT,
	YAW_RIGHT
}						t_camera_rotations;

typedef struct			s_camera
{
	t_vec3_d			position;
	t_vec3_d			world_up;
	double				yaw;
	double				pitch;
	t_vec3_d			vec_up;
	t_vec3_d			vec_right;
	t_vec3_d			vec_front;
	double				velocity;
	double				rotation_velocity;
	t_matrix44_d		view_mat;
	void				(*update)(struct s_camera *);
}						t_camera;

t_camera				*mlx_init_camera(t_vec3_d pos);

void					mlx_camera_update_view_mat(t_camera *self);

void					mlx_camera_move(t_camera *self, t_camera_movement movement);

void					mlx_camera_rotate(t_camera *self, t_camera_rotations rotation);

void					mlx_camera_mouse(t_camera *self, double xoffset, double yoffset);

#endif
