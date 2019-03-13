/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:46:25 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:46:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

t_text					*ft_init_text(t_point2d pos, char *text, t_color color)
{
	t_text				*res;

	if (!(res = malloc(sizeof(t_text))))
		return (NULL);
	res->pos = pos;
	res->render_txt = mlx_text_render_txt;
	res->text = text;
	res->align = LEFT;
	res->color = color;
	return (res);
}
