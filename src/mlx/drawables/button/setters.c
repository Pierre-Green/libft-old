/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:32:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 18:37:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_button		*mlx_button_set_s(t_button *self, void *s)
{
	self->s = s;
	return (self);
}

t_button		*mlx_button_set_uuid(t_button *self, int uuid)
{
	self->uuid = uuid;
	return (self);
}

t_button		*mlx_button_set_enabled(t_button *self, t_bool enabled)
{
	self->enabled = enabled;
	return (self);
}

t_button		*mlx_button_set_onclick(t_button *self,
		void (*onclick)(int, int, void *))
{
	self->onclick = onclick;
	return (self);
}
