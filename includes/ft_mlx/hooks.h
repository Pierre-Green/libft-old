/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:07:26 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 18:47:00 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_HOOKS_H
# define FT_MLX_HOOKS_H
# include <stdlib.h>
# include "ft_math/zone.h"
# define MLX_HOOK_INITIAL_CAPACITY 32

typedef int			t_mouse_btn;

typedef void		(*t_onpress)(int key);

typedef void		(*t_onclick)(t_mouse_btn button, int id, void *s);

typedef struct		s_keyboard_hook
{
	int				key;
	t_onpress		onpress;
	void			*s;
}					t_keyboard_hook;

typedef struct		s_keyboard_hooks
{
	size_t			len;
	size_t			capacity;
	t_keyboard_hook	hooks[];
}					t_keyboard_hooks;

typedef struct		s_mouse_hook
{
	t_zone2d		zone;
	int				uuid;
	t_onclick		onclick;
	void			*s;
}					t_mouse_hook;

typedef struct		s_mouse_hooks
{
	size_t			len;
	size_t			capacity;
	t_mouse_hook	hooks[];
}					t_mouse_hooks;

t_keyboard_hooks	*mlx_init_keyhooks();

t_mouse_hooks		*mlx_init_mousehooks();

void				mlx_add_keyhook(t_keyboard_hooks *hooks, int key,
		t_onpress onpress, void *s);

#endif
