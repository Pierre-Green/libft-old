/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:29:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/25 20:17:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"
#include <math.h>

t_matrix44_d			ft_perspective_matrix44_d(double rad_fov, double near, double far)
{
	double				scale;
	double				a;
	double				b;

	scale = 1 / tan(rad_fov / 2);
	a = -far / (far - near);
	b = -far * near / (far - near);
	return (ft_init44_matrix44_d((t_mat44_d_data){
		-scale, 0, 0, 0,
		0, scale, 0, 0,
		0, 0, a, b,
		0, 0, 1, 0
	}));
}
