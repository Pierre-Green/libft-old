/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 02:18:00 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 14:37:35 by pierre           ###   ########.fr       */
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
