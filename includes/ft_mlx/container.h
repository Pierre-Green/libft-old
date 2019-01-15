/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:50:52 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 19:13:03 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CONTAINER_H
# define FT_MLX_CONTAINER_H
# include <stdint.h>
# include "ft_bool.h"
# include "ft_mlx/ft_mlx.h"

typedef struct	s_container
{
	int16_t		x;
	int16_t		y;
	uint16_t	width;
	uint16_t	height;
	t_drawable	*childs;
	uint8_t		childs_count;
}				t_container;

t_container		*ft_init_container(int16_t x, int16_t y, uint16_t width, uint16_t height);

t_bool			ft_render_container();

#endif