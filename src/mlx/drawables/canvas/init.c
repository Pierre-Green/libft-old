/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:41:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 19:51:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include <mlx.h>

t_canvas				*mlx_init_canvas(t_point2d pos, t_dim2d dim, t_image_carry *(*image)(t_canvas *, void *), void *mlx_ptr, void *s)
{
	t_canvas			*canvas;
	void				*img_ptr;
	char				*data;
	int					params[3];

	if (!(canvas = malloc(sizeof(t_canvas))))
		return (NULL);
	canvas->has_focus = true;
	canvas->s = s;
	canvas->zone = ft_zone2d_from_pdim(pos, dim);
	canvas->image = image;
	canvas->image_intern = mlx_canvas_image_intern;
	img_ptr = mlx_new_image(mlx_ptr, dim.width, dim.height);
	data = mlx_get_data_addr(img_ptr, &params[0], &params[1], &params[2]);
	canvas->img = ft_image_carry_from(img_ptr, &data, params[0], params[1], params[2]);
	return (canvas);
}
