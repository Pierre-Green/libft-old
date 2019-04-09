/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:30:54 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 18:04:40 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CAMERA_H
# define FT_MLX_CAMERA_H
# include <stdlib.h>
# include <math.h>
# include "ft_math/vec.h"
# include "ft_math/matrix.h"
# include "ft_utils.h"

# define CAM_DEFAULT_YAW 0
# define CAM_DEFAULT_PITCH 0.0
# define CAM_DEFAULT_TRANSLATION_VELOCITY 0.05
# define CAM_DEFAULT_ROTATION_VELOCITY 0.2

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

typedef enum			e_camera_modes
{
	PERSPECTIVE
}						t_camera_modes;

typedef struct			s_camera
{
	t_vec3_d			position;
	t_vec3_d			rotation;
	double				trans_velocity;
	double				rotat_velocity;
	t_matrix44_d		view_mat;
	t_camera_modes		mode;
	void				(*update)(struct s_camera *);
}						t_camera;

t_camera				*mlx_init_camera(t_vec3_d pos);

void					mlx_camera_update_view_mat(t_camera *self);

void					mlx_camera_move(t_camera *self,
		t_camera_movement movement);

void					mlx_camera_rotate(t_camera *self,
		t_camera_rotations rotation);

#endif
