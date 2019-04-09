/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:49:25 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 18:03:33 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"

static void					ft_copy_drawables(t_drawables *dest, t_drawables *src)
{
	int						current;

	current = -1;
	while (++current < (int)src->len)
		ft_add_drawable_to_drawables(&dest, src->drawables[current]);
}

t_drawables					*ft_add_drawable_to_drawables(t_drawables **dest, t_drawable drawable)
{
	t_drawables				*new;
	size_t					capacity;

	if (*dest)
		capacity = (*dest)->capacity << 1;
	else
		capacity = MLX_DRAWABLE_INITIAL_CAPACITY;
	if (!*dest || (*dest)->len == (*dest)->capacity)
	{
		if (!(new = malloc(sizeof(t_drawables) + sizeof(t_drawable) * capacity)))
			return (NULL);
		new->capacity = capacity;
		new->len = 0;
		if (*dest)
			ft_copy_drawables(new, (*dest));
		*dest = new;
	}
	(*dest)->drawables[(*dest)->len] = drawable;
	(*dest)->len++;
	return (*dest);
}

t_drawable					ft_init_drawable(t_drawable_types type,
		void *value)
{
	t_drawable				drawable;
	t_drwble				drwble;

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
	drawable.type = type;
	drawable.drawable = drwble;
	return (drawable);
}

