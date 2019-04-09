/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:29:45 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 17:09:15 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

void			mlx_container_add_child(t_container *self, t_drawable drawable)
{
	ft_add_drawable_to_drawables(&self->childs, drawable);
}
