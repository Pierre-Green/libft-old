/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:18:27 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 16:32:00 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CANVAS_H
# define FT_MLX_CANVAS_H
# include "ft_math/zone.h"
# include "ft_mlx/image.h"
# include "ft_mlx/camera.h"
# include "ft_mlx/color.h"
# include "ft_mlx/hooks.h"

typedef struct			s_canvas
{
	t_zone2d			zone;
	void				*s;
	t_image_carry		*img;
	t_image_carry		*(*image_intern)(struct s_canvas *, t_point2d offset,
			t_image_carry *);
	t_image_carry		*(*image)(struct s_canvas *, void *, t_image_carry *);
	void				(*register_events)(struct s_canvas *, t_point2d offset,
			void *s);
	t_keyboard_hooks	*keyboard_hooks;
	t_mouse_hooks		*mouse_hooks;
	t_motion_hooks		*motion_hooks;
	t_color				background_color;
}						t_canvas;

t_canvas				*mlx_init_canvas(t_point2d pos, t_dim2d dim);

t_image_carry			*mlx_canvas_image_intern(t_canvas *self,
		t_point2d offset, t_image_carry *image_carry);

void					mlx_canvas_background(t_canvas *canvas);

void					mlx_canvas_draw_line(t_canvas *canvas, t_point2d from,
		t_point2d to, t_color color);

void					mlx_canvas_draw_rect(t_canvas *canvas, t_zone2d zone,
		t_color color);

void					mlx_canvas_register_events(t_canvas *canvas,
		t_point2d offset, void *s);

void					mlx_kill_canvas(t_canvas **canvas, void *mlx_ptr);

#endif
