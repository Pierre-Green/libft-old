/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:33:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 18:40:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_button				*mlx_init_button(t_point2d pos, t_dim2d dim,
		t_color color, char *text)
{
	t_button			*button;

	if (!(button = malloc(sizeof(t_button))))
		return (NULL);
	button->pos = pos;
	button->dim = dim;
	button->image = mlx_button_image;
	button->s = NULL;
	button->render_txt = mlx_button_render_txt;
	button->background_color = color;
	button->text = ft_init_text(POS(0, 0), text, 0xFFFFFF);
	button->text->align = CENTER;
	button->onclick = NULL;
	button->enabled = TRUE;
	button->disabled_background_color = 0xA0A0A0;
	button->uuid = 0;
	button->set_s = mlx_button_set_s;
	button->set_uuid = mlx_button_set_uuid;
	button->set_enabled = mlx_button_set_enabled;
	button->set_onclick = mlx_button_set_onclick;
	return (button);
}
