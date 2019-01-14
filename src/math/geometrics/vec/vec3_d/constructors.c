/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:55:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:09:52 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_d		ft_init0_vec3_d(void)
{
	t_vec3_d	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

t_vec3_d		ft_init1_vec3_d(double a)
{
	t_vec3_d	vec;

	vec.x = a;
	vec.y = a;
	vec.z = a;
	return (vec);
}

t_vec3_d		ft_init3_vec3_d(double x, double y, double z)
{
	t_vec3_d	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}
