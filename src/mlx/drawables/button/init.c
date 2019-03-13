/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 14:00:51 by pierre            #+#    #+#             */
/*   Updated: 2019/03/13 19:28:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"


t_button				*mlx_init_button(t_point2d pos, t_dim2d dim, t_color color, char *text, int uuid)
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
	button->uuid = uuid;
	return (button);
}
