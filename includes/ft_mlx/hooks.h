/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:07:26 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 21:00:25 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_HOOKS_H
# define FT_MLX_HOOKS_H
# include <stdlib.h>
# include "ft_math/zone.h"
# define MLX_HOOK_INITIAL_CAPACITY 64

typedef int			t_mouse_btn;

typedef void		(*t_onpress)(void *s);

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
	void			(*add)(struct s_keyboard_hooks *, int, t_onpress,
			void *);
	t_keyboard_hook	hooks[];
}					t_keyboard_hooks;

typedef struct		s_mouse_hook
{
	t_zone2d		zone;
	int				id;
	t_onclick		onclick;
	void			*s;
}					t_mouse_hook;

typedef struct		s_mouse_hooks
{
	size_t			len;
	size_t			capacity;
	void			(*add)(struct s_mouse_hooks *, int, t_zone2d,
			t_onclick, void *);
	t_mouse_hook	hooks[];
}					t_mouse_hooks;

t_keyboard_hooks	*mlx_init_keyhooks();

t_mouse_hooks		*mlx_init_mousehooks();

void				mlx_add_keyhook(t_keyboard_hooks *hooks, int key,
		t_onpress onpress, void *s);

void				mlx_add_mousehook(t_mouse_hooks *hooks, int id,
		t_zone2d zone, t_onclick onclick, void *s);

void				mlx_copy_keyhooks(t_keyboard_hooks *dest, t_keyboard_hooks *src);

void				mlx_copy_mousehooks(t_mouse_hooks *dest, t_mouse_hooks *src);

void				mlx_copy_mousehooks_offset(t_mouse_hooks *dest,
		t_mouse_hooks *src, t_point2d offset);

#endif
