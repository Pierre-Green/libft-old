/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:09:38 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 19:16:45 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

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

#endif
