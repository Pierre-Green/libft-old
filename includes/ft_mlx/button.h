/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:02:01 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 02:35:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_BUTTON_H
# define FT_MLX_BUTTON_H
# include <stdlib.h>
# include "ft_mlx/color.h"
# include "ft_mlx/text.h"
# include "ft_math/point.h"
# include "ft_math/dim.h"

typedef struct		s_button
{
	t_text			*child;
	void			(*onclick)();
	int				(*draw)(struct s_button *, t_point2d, void *);
	t_color			background_color;
	t_dim2d			dim;
	t_point2d		pos;
}					t_button;

#endif
