/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:49:36 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"
#include "ft_str.h"
#include "ft_utils.h"

char 					*ft_matrix44_i8_tostring(t_matrix44_i8 self)
{
	char 				*res;
	uint8_t 			x;
	uint8_t 			y;

	res = ft_strnew(((4 + 1) * 4 * 4) + 1);
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			ft_strcat(res, ft_itoa(self.matrix[y][x]));
			if (x != 3)
				ft_strcat(res, " ");
			x++;
		}
		ft_strcat(res, "\n");
		y++;
	}
	return (res);
}