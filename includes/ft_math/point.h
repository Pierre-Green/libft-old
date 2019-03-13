/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:21:37 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:00:52 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_POINT_H
# define FT_MATH_POINT_H
# define POS(x, y)(ft_point2d_pos(x, y))
# define DDSUM(a, b)(ft_point2d_sum(a, b))

typedef struct		s_point2d
{
	int				x;
	int				y;
}					t_point2d;

t_point2d			ft_point2d_pos(int x, int y);

t_point2d			ft_point2d_sum(t_point2d a, t_point2d b);

#endif
