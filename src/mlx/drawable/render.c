/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:23:35 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 02:35:52 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawable.h"

int						ft_drawable_routerender(t_drawable drawable, t_point2d offset, void *s)
{
	if (drawable.type == TEXT)
		return (((t_text *)drawable.drawable)->draw(drawable.drawable, offset, s));
	if (drawable.type == BUTTON)
		return (((t_button *)drawable.drawable)->draw(drawable.drawable, offset, s));
	return (-1);
}
