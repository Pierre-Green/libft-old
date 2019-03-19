/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:41:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/19 17:32:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"

t_canvas				*mlx_init_canvas(t_point2d pos, t_dim2d dim)
{
	t_canvas			*canvas;

	if (!(canvas = malloc(sizeof(t_canvas))))
		return (NULL);
	canvas->has_focus = TRUE;
	canvas->s = NULL;
	canvas->zone = ft_zone2d_from_pdim(pos, dim);
	canvas->image = NULL;
	canvas->img = NULL;
	canvas->image_intern = mlx_canvas_image_intern;
	canvas->background_color = 0x000000;
	return (canvas);
}
