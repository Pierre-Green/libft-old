/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matmut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 20:09:22 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/08 19:15:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_d				ft_vec3_d_matmut(t_vec3_d self, t_matrix44_d mat)
{
	t_vec3_d			res;
	double				w;

	res.x = self.x * mat.matrix[0][0] + self.y * mat.matrix[1][0]
		+ self.z * mat.matrix[2][0] + mat.matrix[3][0];
	res.y = self.x * mat.matrix[0][1] + self.y * mat.matrix[1][1]
		+ self.z * mat.matrix[2][1] + mat.matrix[3][1];
	res.z = self.x * mat.matrix[0][2] + self.y * mat.matrix[1][2]
		+ self.z * mat.matrix[2][2] + mat.matrix[3][2];
	w = self.x * mat.matrix[0][3] + self.y * mat.matrix[1][3]
		+ self.z * mat.matrix[2][3] + mat.matrix[3][3];
	if (w != 1)
	{
		res.x /= w;
		res.y /= w;
		res.z /= w;
	}
	return (res);
}
