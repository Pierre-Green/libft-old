/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:32:19 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/07 02:22:44 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_DIM_H
# define FT_MLX_DIM_H
# include <stdlib.h>
# define DIM(width, height) (ft_dim2d_dim(width, height))

typedef struct		s_dim2d
{
	size_t			width;
	size_t			height;
}					t_dim2d;

t_dim2d				ft_dim2d_dim(size_t width, size_t height);

#endif
