/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:29:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/22 17:47:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"
#include <math.h>

t_matrix44_d			ft_perspective_matrix44_d(double rad_fov,
		double aspect_ratio, double near, double far)
{
	t_matrix44_d		mat;

	mat = ft_init0_matrix44_d();
	mat.matrix[0][0] = 1 / (aspect_ratio * tan(rad_fov / 2));
	mat.matrix[1][1] = 1 / tan(rad_fov / 2);
	mat.matrix[2][2] = (-near - far) / (near - far);
	mat.matrix[2][3] = 1;
	mat.matrix[3][2] = 2 * near * far / (near - far);
	return (mat);
}
