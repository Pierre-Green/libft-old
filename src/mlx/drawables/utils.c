/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:49:25 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 21:36:46 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

void						ft_add_drawable_to_drawables(t_drawables *dest,
		t_drawable *src)
{
	t_drawables				*node;

	node = dest;
	while (node->next)
		node = node->next;
	if (node->drawable == NULL)
		node->drawable = src;
	else
	{
		node->next = (t_drawables *)malloc(sizeof(t_drawables));
		node->next->drawable = src;
		node->next->next = NULL;
	}
}

t_drawable					*ft_drawable_at(t_drawables *lst, size_t i)
{
	const t_drawables		*node = lst;
	size_t					curr;

	curr = 0;
	while (curr < i)
	{
		if (!node->next)
			return (NULL);
		node = node->next;
		curr++;
	}
	return ((t_drawable *)node->drawable);
}

t_drawable					*ft_init_drawable(t_drawable_types type,
		void *value)
{
	t_drawable				*drawable;
	t_drwble				drwble;

	if (!(drawable = malloc(sizeof(t_drawable))))
		return (NULL);
	if (type == CONTAINER)
		drwble.container = value;
	if (type == TEXT)
		drwble.text = value;
	if (type == BUTTON)
		drwble.button = value;
	if (type == PAGINATION)
		drwble.pagination = value;
	if (type == CANVAS)
		drwble.canvas = value;
	drawable->type = type;
	drawable->drawable = drwble;
	return (drawable);
}

