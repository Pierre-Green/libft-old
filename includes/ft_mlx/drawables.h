/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:14:46 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/22 15:47:46 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DRAWABLE_H
# define FT_MLX_DRAWABLE_H
# include "ft_math/point.h"
# include "ft_math/dim.h"
# include "ft_mlx/color.h"

# define OFFSET_NULL (struct t_point2d { x = 0; y = 0; })

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

typedef struct			s_drawables
{
	t_drawable			*drawable;
	struct s_drawables	*next;
}						t_drawables;

typedef struct			s_text
{
	char				*text;
	char				*(*image)(struct s_text *);
	t_dim2d				dim;
	t_point2d			pos;
}						t_text;

typedef struct			s_button
{
	t_drawable			*child;
	char				*(*image)(struct s_button *, t_point2d, char **);
	void				(*onclick)();
	t_color				background_color;
	t_dim2d				dim;
	t_point2d			pos;
}						t_button;

typedef struct			s_container
{
	t_drawables			*childs;
	char				*(*image)(struct s_container *, t_point2d, char **);
	void				(*add_child)(struct s_container *, t_drawable *);
	t_color				background_color;
	t_dim2d				dim;
	t_point2d			pos;
}						t_container;

t_container				*ft_init_container(t_point2d pos, t_dim2d dim);

void					ft_add_drawable_to_drawables(t_drawables *dest, t_drawable *src);

int						ft_drawable_routerender(t_drawable drawable, t_point2d offset, void *);

#endif