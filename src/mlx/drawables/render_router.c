/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_router.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:23:55 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 19:25:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_bool				ft_render_drawable(t_drawable drawable)
{
	if (drawable.data_type == CONTAINER)
		return (true);
	if (drawable.data_type == VEC2_I16)
		return (true);
	return (false);
}
