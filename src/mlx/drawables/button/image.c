/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 19:28:31 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:34:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

char				*mlx_button_image(t_button *self, t_point2d offset,
		t_image_carry *carry)
{
	mlx_button_background(self, offset, carry);
	return (*carry->data);
}
