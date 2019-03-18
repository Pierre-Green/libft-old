/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:18:27 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/18 18:28:52 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CANVAS_H
# define FT_MLX_CANVAS_H
# include "ft_math/zone.h"
# include "ft_mlx/image.h"
# include "ft_mlx/camera.h"

typedef struct			s_canvas
{
	t_zone2d			zone;
	void				*s;
	t_image_carry		*img;
	t_image_carry		*(*image_intern)(struct s_canvas *, t_point2d offset, t_image_carry *);
	t_image_carry		*(*image)(struct s_canvas *, void *);
	t_bool				has_focus;
}						t_canvas;

t_canvas				*mlx_init_canvas(t_point2d pos, t_dim2d dim, t_image_carry *(*image)(t_canvas *, void *), void *mlx_ptr);

t_image_carry			*mlx_canvas_image_intern(t_canvas *, t_point2d offset, t_image_carry *);

#endif
