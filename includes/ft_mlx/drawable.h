/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:14:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 02:53:47 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DRAWABLE_H
# define FT_MLX_DRAWABLE_H
# include "ft_math/point.h"

typedef enum			e_drawable_types
{
						CONTAINER,
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
