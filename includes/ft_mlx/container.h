/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:50:52 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 18:00:12 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CONTAINER
# define FT_MLX_CONTAINER
# include <stdint.h>

typedef struct	s_container
{
	int16_t		x;
	int16_t		y;
	uint16_t	width;
	uint16_t	height;
	void		**childs;
	uint8_t		childs_count;
}				t_container;

t_container		*ft_init_container(int16_t x, int16_t y, uint16_t width, uint16_t height);

#endif
