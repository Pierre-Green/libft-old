/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:25:21 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:25:23 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/point.h"

t_point2d			ft_point2d_pos(int x, int y)
{
	return ((t_point2d){ x, y });
}

t_point2d			ft_point2d_sum(t_point2d a, t_point2d b)
{
	return ((t_point2d){ a.x + b.x, a.y + b.y });
}
