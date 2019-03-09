/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:15:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/10 00:25:26 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_WINDOW_H
# define FT_MLX_WINDOW_H
# include <stdlib.h>
# include "ft_bool.h"
# include "ft_lst.h"
# include "ft_mlx/drawables.h"
# include "ft_math/zone.h"
# define DEFAULT_WIDTH 500
# define DEFAULT_HEIGHT 1000

typedef void *				t_winptr;

typedef int					t_mouse;

typedef struct				s_mouse_hooks
{
	t_zone2d				zone;
	int						uuid;
	void					(*onclick)(t_mouse, int target, void *);
	struct s_mouse_hooks	*next;
}							t_mouse_hooks;

typedef struct				s_window
{
	t_winptr				*ptr;
	size_t					width;
	size_t					height;
	t_bool					should_render_every_frame;
	int						(*render)(void *);
	void					(*add_keyboard_hook)(struct s_window *, int (*f)(int, void *));
	t_list					*keyboard_hooks;
	void					(*add_lkeyboard_hook)(struct s_window *, int (*f)(int, void *));
	t_list					*lkeyboard_hooks;
	t_mouse_hooks			*(*add_mouse_hook)(struct s_window *, int, t_zone2d, void (*f)(t_mouse, int, void *));
	t_mouse_hooks			*mouse_hooks;
	struct s_window 		*next;
}							t_window;

typedef struct				s_hook_carry
{
	void					*state;
	t_window				*window;

}							t_hook_carry;

int							keyboard_hooks_dispatcher(int keycode, void *p_carry);

int							lkeyboard_hooks_dispatcher(int keycode, void *p_carry);

int							mouse_hooks_dispatcher(int mouse, int x, int y, void *p_carry);

t_mouse_hooks				*add_mouse_hook(t_window *window, int, t_zone2d zone, void (*f)(t_mouse, int, void *));

void						add_lkeyboard_hook(t_window *window, int (*f)(int, void *));

void						add_keyboard_hook(t_window *window, int (*f)(int, void *));

t_window					*ft_init_window();

#endif
