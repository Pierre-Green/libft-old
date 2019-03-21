/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:15:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/21 16:56:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_WINDOW_H
# define FT_MLX_WINDOW_H
# include <stdlib.h>
# include "ft_bool.h"
# include "ft_lst.h"
# include "ft_mlx/drawables.h"
# include "ft_math/zone.h"
# include <mlx.h>
# define DEFAULT_WIDTH 500
# define DEFAULT_HEIGHT 1000

typedef void *				t_winptr;

typedef void *				t_mlxptr;

typedef int					t_mouse;

typedef struct				s_mouse_hooks
{
	t_zone2d				zone;
	int						uuid;
	void					(*onclick)(t_mouse, int target, void *);
	void					*carry;
	struct s_mouse_hooks	*next;
}							t_mouse_hooks;

typedef struct				s_keyboard_hooks
{
	int						keycode;
	void					(*onpress)(void *);
	void					*carry;
	struct s_keyboard_hooks	*next;
}							t_keyboard_hooks;

typedef struct				s_window
{
	t_winptr				*ptr;
	t_mlxptr				*mlx;
	void					*carry;
	size_t					width;
	size_t					height;
	t_bool					should_render_every_frame;
	t_bool					close_on_esc;
	int						(*render)(struct s_window *);
	t_image_carry			*img;
	struct s_container		*body;
	t_keyboard_hooks		*(*add_keyboard_hook)(struct s_window *, int,
			void (*f)(void *), void *);
	t_keyboard_hooks		*keyboard_hooks;
	t_mouse_hooks			*(*add_mouse_hook)(struct s_window *,
			int, t_zone2d, void (*f)(t_mouse, int, void *), void *s);
	t_mouse_hooks			*mouse_hooks;
}							t_window;

typedef struct				s_hook_carry
{
	void					*state;
	t_window				*window;

}							t_hook_carry;

int							keyboard_hooks_dispatcher(int keycode,
		void *p_carry);

int							mouse_hooks_dispatcher(int mouse, int x,
		int y, void *p_carry);

t_mouse_hooks				*add_mouse_hook(t_window *window, int id,
		t_zone2d zone, void (*f)(t_mouse, int, void *), void *s);

t_keyboard_hooks			*add_keyboard_hook(t_window *window, int keycode,
		void (*f)(void *), void *s);

t_window					*ft_init_window(void *mlx_ptr,
		t_dim2d dims, char *title, void *carry);

int							mlx_render_window(t_window *window);

#endif
