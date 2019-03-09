/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:00:51 by pierre            #+#    #+#             */
/*   Updated: 2019/03/10 00:26:57 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static char				*image(t_button *self, t_point2d offset, t_image_carry *carry)
{
	mlx_button_background(self, offset, carry);
	return (*carry->data);
}

t_button				*mlx_init_button(t_point2d pos, t_dim2d dim, t_color color, char *text, int uuid)
{
	t_button			*button;

	if (!(button = malloc(sizeof(t_button))))
		return (NULL);
	button->pos = pos;
	button->dim = dim;
	button->image = image;
	button->render_txt = mlx_button_render_txt;
	button->background_color = color;
	button->text = text;
	button->onclick = NULL;
	button->uuid = uuid;
	return (button);
}
