/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:15:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 21:08:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_WINDOW_H
# define FT_MLX_WINDOW_H
# include <stdlib.h>
# include "ft_bool.h"
# include "ft_lst.h"
# include "ft_mlx/drawables.h"
# include "ft_math/zone.h"
# include "ft_mlx/hooks.h"
# include <mlx.h>
# define DEFAULT_WIDTH 500
# define DEFAULT_HEIGHT 1000

typedef void *				t_winptr;

typedef void *				t_mlxptr;

typedef struct				s_hook_carry
{
	void					*state;
	struct s_window			*window;
}							t_hook_carry;

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
	t_keyboard_hooks		*keyboard_hooks;
	t_mouse_hooks			*mouse_hooks;
	t_motion_hooks			*motion_hooks;
	void					(*kill)(struct s_window *);
}							t_window;

t_window					*ft_init_window(void *mlx_ptr,
		t_dim2d dims, char *title, void *carry);

void						mlx_kill_window(t_window *self);

int							mlx_render_window(t_window *window);

int							keyboard_hooks_dispatcher(int keycode,
		void *p_carry);

int							mouse_hooks_dispatcher(int mouse, int x,
		int y, void *p_carry);

int							motion_hooks_dispatcher(int x, int y,
		void *p_carry);

#endif
