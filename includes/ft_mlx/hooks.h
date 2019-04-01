/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 18:07:26 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/01 19:28:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_HOOKS_H
# define FT_MLX_HOOKS_H
# include <stdlib.h>
# include "ft_math/zone.h"
# define MLX_HOOK_INITIAL_CAPACITY 64

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_UP 126
# define KEY_ARROW_RIGHT 124
# define KEY_ARROW_DOWN 125

typedef int			t_mouse_btn;

typedef void		(*t_onpress)(void *s);

typedef void		(*t_onclick)(t_mouse_btn button, int id, void *s);

typedef void		(*t_onmotion)(int x, int y, void *s);

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
	struct s_keyboard_hooks		*(*add)(struct s_keyboard_hooks *, int, t_onpress,
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
	struct s_mouse_hooks	*(*add)(struct s_mouse_hooks *, int, t_zone2d,
			t_onclick, void *);
	t_mouse_hook	hooks[];
}					t_mouse_hooks;

typedef struct		s_motion_hook
{
	t_zone2d		zone;
	t_onmotion		onmotion;
	void			*s;
}					t_motion_hook;

typedef struct		s_motion_hooks
{
	size_t			len;
	size_t			capacity;
	struct s_motion_hooks		*(*add)(struct s_motion_hooks *, t_zone2d,
			t_onmotion, void *);
	t_motion_hook	hooks[];
}					t_motion_hooks;

t_keyboard_hooks	*mlx_init_keyhooks();

t_mouse_hooks		*mlx_init_mousehooks();

t_motion_hooks		*mlx_init_motionhooks();

t_keyboard_hooks		*mlx_add_keyhook(t_keyboard_hooks *hooks, int key,
		t_onpress onpress, void *s);

t_mouse_hooks			*mlx_add_mousehook(t_mouse_hooks *hooks, int id,
		t_zone2d zone, t_onclick onclick, void *s);

t_motion_hooks			*mlx_add_motionhook(t_motion_hooks *hooks, t_zone2d zone,
		t_onmotion onmotion, void *s);

void				mlx_copy_keyhooks(t_keyboard_hooks *dest,
		t_keyboard_hooks *src);

void				mlx_copy_mousehooks(t_mouse_hooks *dest,
		t_mouse_hooks *src);

void				mlx_copy_mousehooks_offset(t_mouse_hooks *dest,
		t_mouse_hooks *src, t_point2d offset);

void				mlx_copy_motionhooks(t_motion_hooks *dest,
		t_motion_hooks *src);

void				mlx_kill_keyhooks(t_keyboard_hooks *hooks);

void				mlx_kill_mousehooks(t_mouse_hooks *hooks);

void				mlx_kill_motionhooks(t_motion_hooks *hooks);

#endif
