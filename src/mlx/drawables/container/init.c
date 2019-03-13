/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:19:09 by pierre            #+#    #+#             */
/*   Updated: 2019/03/13 19:30:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "background.c"


t_container			*ft_init_container(t_point2d pos, t_dim2d dim, t_color color)
{
	t_container		*container;

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
