/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:16:21 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"

t_matrix44_i8			ft_init0_matrix44_i8()
{
	t_matrix44_i8		matrix;
	uint8_t 			x;
	uint8_t 			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			matrix.matrix[y][x] = 0;
			x++;
		}
		y++;
	}
	return (matrix);
}

t_matrix44_i8			ft_init1_matrix44_i8(int8_t a)
{
	t_matrix44_i8		matrix;
	uint8_t 			x;
	uint8_t 			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			matrix.matrix[y][x] = a;
			x++;
		}
		y++;
	}
	return (matrix);
}

t_matrix44_i8			ft_init44_matrix44_i8(int8_t matrixxx[4][4])
{
	t_matrix44_i8		matrix;
	uint8_t 			x;
	uint8_t 			y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			matrix.matrix[y][x] = matrixxx[y][x];
			x++;
		}
		y++;
	}
	return (matrix);
}
