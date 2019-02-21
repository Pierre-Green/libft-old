/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:14:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 02:36:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DRAWABLE_H
# define FT_MLX_DRAWABLE_H
# include "ft_math/point.h"
# include "ft_mlx/button.h"
# include "ft_mlx/text.h"

typedef enum			e_drawable_types
{
						TEXT,
						BUTTON,
						NONE
}						t_drawable_types;

typedef struct			s_drawable
{
	void				*drawable;
	t_drawable_types	type;
}						t_drawable;

int						ft_drawable_routerender(t_drawable drawable, t_point2d offset, void *);

#endif
