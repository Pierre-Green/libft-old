/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 02:48:40 by pierre            #+#    #+#             */
/*   Updated: 2019/03/07 03:11:38 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_mlx/window.h"
#include <mlx.h>

t_image_carry				*mlx_container_render(t_container *container, void *mlx_ptr, void *win, t_image_carry *old)
{
	const t_window			*window = win;
	void					*tmptr;
	char					*tmpch;
	int						params[3];

	if (!old)
	{
		tmptr = mlx_new_image(mlx_ptr, window->width, window->height);
		tmpch = mlx_get_data_addr(tmptr, &params[0], &params[1], &params[2]);
		old = ft_image_carry_from(&tmpch, params[0], params[1], params[2]);
	}
	*old->data = container->image(container, POS(0, 0), old);
	mlx_put_image_to_window(mlx_ptr, window->ptr, old->data, 0, 0);
	return (old);
}
