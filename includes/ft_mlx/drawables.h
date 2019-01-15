/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:09:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 19:28:19 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DRAWABLES_H
# define FT_MLX_DRAWABLES_H
# include <stdint.h>
# include "ft_bool.h"
# include "ft_math/vec.h"

typedef enum		s_drawable_type
{
					CONTAINER,
					VEC2_I16
}					t_drawable_type;

typedef struct		s_drawable
{
	void			*data;
	t_drawable_type	data_type;
}					t_drawable;

t_bool				ft_render_drawable(t_drawable drawable);

t_bool				ft_render_vec2_i16(t_vec2_i16 vec);

typedef struct		s_container
{
	int16_t			x;
	int16_t			y;
	uint16_t		width;
	uint16_t		height;
	t_drawable		*childs;
	uint8_t			childs_count;
}					t_container;

t_container			*ft_init_container(int16_t x, int16_t y, uint16_t width, uint16_t height);

t_bool				ft_render_container();

#endif
