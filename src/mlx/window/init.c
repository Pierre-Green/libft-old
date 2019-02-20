/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:39:18 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 00:35:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/window.h"

t_window			*ft_init_window()
{
	t_window		*win;

	if (!(win = (t_window *)malloc(sizeof(t_window))))
		return (NULL);
	win->render = NULL;
	win->longkeypress = NULL;
	win->keypress = NULL;
	win->mouse = NULL;
	win->width = DEFAULT_WIDTH;
	win->height = DEFAULT_HEIGHT;
	win->ptr = NULL;
	win->next = NULL;
	return (win);
}
