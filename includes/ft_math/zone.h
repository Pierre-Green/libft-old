/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:01:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:01:50 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_ZONE_H
# define FT_MATH_ZONE_H
# include "ft_math/point.h"
# include "ft_math/dim.h"
# include "ft_bool.h"

typedef struct		s_zone2d
{
	t_point2d		pos;
	t_dim2d			dim;
}					t_zone2d;

t_bool				ft_is_point_in_zone2d(t_zone2d zone, t_point2d point);

t_zone2d			ft_zone2d_from_pdim(t_point2d pos, t_dim2d dim);

#endif
