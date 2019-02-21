/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:15:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 01:53:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_WINDOW_H
# define FT_MLX_WINDOW_H
# include <stdlib.h>
# include "ft_bool.h"
# include "ft_lst.h"
# define DEFAULT_WIDTH 500
# define DEFAULT_HEIGHT 1000

typedef void *		t_winptr;

typedef struct		s_window
{
	t_winptr		*ptr;
	size_t			width;
	size_t			height;
	t_bool			should_render_every_frame;
	int				(*render)(void *);
	void			(*add_keyboard_hook)(struct s_window *, int (*f)(int, void *));
	t_list			*keyboard_hooks;
	void			(*add_lkeyboard_hook)(struct s_window *, int (*f)(int, void *));
	t_list			*lkeyboard_hooks;
	void			(*add_mouse_hook)(struct s_window *, int (*f)(int, int, int, void *));
	t_list			*mouse_hooks;
	struct s_window *next;
}					t_window;

t_window			*ft_init_window();

#endif
