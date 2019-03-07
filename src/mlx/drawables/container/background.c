/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 01:22:47 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 02:00:37 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

void	mlx_container_background(t_container *container, t_point2d offset, t_image_carry *carry)
{
	size_t			x;
	size_t			y;

	y = offset.y + container->pos.y;
	while ((y - (offset.y + container->pos.y)) < container->dim.height)
	{
		x = offset.x + container->pos.x;
		while ((x - (offset.x + container->pos.x)) < container->dim.width)
		{
			ft_put_pixel_to_image(carry, x, y);
			x++;
		}
		y++;
	}
}
