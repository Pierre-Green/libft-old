/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:34:02 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 21:40:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/image.h"
#include <mlx.h>
#include "ft_mem.h"

void			mlx_kill_image_carry(t_image_carry *self, void *mlx_ptr)
{
	if (self->img_ptr)
		mlx_destroy_image(mlx_ptr, self->img_ptr);
	else
		ft_memdel((void **)self->data);
	ft_memdel((void **)self);
}
