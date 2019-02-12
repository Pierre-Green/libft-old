/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:43:35 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/12 19:50:40 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"

t_matrix44_d			ft_multiply_matrix44_d(t_matrix44_d m1, t_matrix44_d m2)
{
	t_matrix44_d		matrix;
	uint8_t				x;
	uint8_t				y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			matrix.matrix[y][x] = m1.matrix[y][0] * m2.matrix[0][x]
								+ m1.matrix[y][1] * m2.matrix[1][x]
								+ m1.matrix[y][2] * m2.matrix[2][x]
								+ m1.matrix[y][3] * m2.matrix[3][x];
			x++;
		}
		y++;
	}
	return (matrix);
}
