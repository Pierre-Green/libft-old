/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:38:20 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:38:46 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_container		*ft_init_container(t_point2d pos, t_dim2d dim, t_color color)
{
	t_container	*container;

	if (!(container = (t_container *)malloc(sizeof(t_container))))
		return (NULL);
	container->childs = NULL;
	container->add_child = mlx_container_add_child;
	container->image = mlx_container_image;
	container->render = mlx_container_render;
	container->render_txt = mlx_container_render_txt;
	container->background_color = color;
	container->dim = dim;
	container->pos = pos;
	return (container);
}
