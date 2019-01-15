/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:56:43 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/15 18:00:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/container.h"
#include "ft_mem.h"

t_container		*ft_init_container(int16_t x, int16_t y, uint16_t width, uint16_t height)
{
	t_container	*container;

	if (!(container = ft_memalloc(sizeof(t_container))))
		return (NULL);
	container->x = x;
	container->y = y;
	container->width = width;
	container->height = height;
	container->childs = NULL;
	container->childs_count = 0;
	return (container);
}
