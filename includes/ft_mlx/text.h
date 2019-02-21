/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:31:00 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 02:34:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_TEXT_H
# define FT_MLX_TEXT_H
# include "ft_math/point.h"
# include "ft_math/dim.h"

typedef struct		s_text
{
	char			*text;
	int				(*draw)(struct s_text *, t_point2d, void *);
	t_dim2d			dim;
	t_point2d		pos;
}					t_text;

#endif
