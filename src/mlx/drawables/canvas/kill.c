/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:28:50 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 16:31:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/canvas.h"
#include "ft_mem.h"

void					mlx_kill_canvas(t_canvas **canvas, void *mlx_ptr)
{
	mlx_kill_image_carry((*canvas)->img, mlx_ptr);
	mlx_kill_keyhooks((*canvas)->keyboard_hooks);
	mlx_kill_mousehooks((*canvas)->mouse_hooks);
	mlx_kill_motionhooks((*canvas)->motion_hooks);
}
