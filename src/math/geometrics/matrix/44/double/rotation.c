/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:20:54 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/02 18:27:45 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"
#include "ft_utils.h"
#include <math.h>

t_matrix44_d			ft_rotation_matrix44_d_y(double angle)
{
	const double		rad_angle = ft_degrees_to_radian(angle);
	const double		an_cos = cos(rad_angle);
	const double		an_sin = sin(rad_angle);

	return (ft_init44_matrix44_d((t_mat44_d_data){
			an_cos, 0, an_sin, 0,
			0, 1, 0, 0,
			-an_sin, 0, an_cos, 0,
			0, 0, 0, 1
	}));
}
