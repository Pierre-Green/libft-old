/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:14:55 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/10 19:21:39 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"
#include "ft_mem.h"

t_vec2			construct_vec2(t_vec_type type, void *x, void *y)
{
	t_vec2		vec;

	vec.type = type;
	vec.size = sizeof(*x);
	if (!(vec.x = ft_memalloc(sizeof(vec.size))))
		return (vec);
	if (!(vec.y = ft_memalloc(sizeof(vec.size))))
		return (vec);
	vec.y = y;
	vec.x = x;
	return (vec);
}