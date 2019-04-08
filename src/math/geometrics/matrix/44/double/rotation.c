/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:02:23 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 17:16:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"
#include "ft_utils.h"

t_matrix44_d			ft_rotation_matrix44_d_x(double x)
{
	const double		rad_x = ft_degrees_to_radian(x);
	const double		sin_x = sin(rad_x);
	const double		cos_x = cos(rad_x);

	return (ft_init44_matrix44_d((t_mat44_d_data){
		1, 0, 0, 0,
		0, cos_x, sin_x, 0,
		0, -sin_x, cos_x, 0,
		0, 0, 0, 1
	}));
}

t_matrix44_d			ft_rotation_matrix44_d_y(double y)
{
	const double		rad_y = ft_degrees_to_radian(y);
	const double		sin_y = sin(rad_y);
	const double		cos_y = cos(rad_y);

	return (ft_init44_matrix44_d((t_mat44_d_data){
		cos_y, 0, -sin_y, 0,
		0, 1, 0, 0,
		sin_y, 0, cos_y, 0,
		0, 0, 0, 1
	}));
}

t_matrix44_d			ft_rotation_matrix44_d_z(double z)
{
	const double		rad_z = ft_degrees_to_radian(z);
	const double		sin_z = sin(rad_z);
	const double		cos_z = cos(rad_z);

	return (ft_init44_matrix44_d((t_mat44_d_data){
		cos_z, sin_z, 0, 0,
		-sin_z, cos_z, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	}));
}

t_matrix44_d			ft_rotation_matrix44_d(double x, double y, double z)
{
	const t_matrix44_d	mat_rot_x = ft_rotation_matrix44_d_x(x);
	const t_matrix44_d	mat_rot_y = ft_rotation_matrix44_d_y(y);
	const t_matrix44_d	mat_rot_z = ft_rotation_matrix44_d_z(z);

	return (ft_multiply_matrix44_d(mat_rot_x,
				ft_multiply_matrix44_d(mat_rot_y, mat_rot_z)));
}
