/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 23:15:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/21 00:44:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_WINDOW_H
# define FT_MLX_WINDOW_H
# include <stdlib.h>
# include "ft_bool.h"
# define DEFAULT_WIDTH 500
# define DEFAULT_HEIGHT 1000

typedef void *		t_winptr;

typedef struct		s_window
{
	t_winptr		*ptr;
	size_t			width;
	size_t			height;
	int				(*render)(void *);
	int				(*keypress)(int, void *);
	int				(*longkeypress)(int, void *);
	int				(*mouse)(int, int, int, void *);
	t_bool			should_render_every_frame;
	struct s_window *next;
}					t_window;

t_window			*ft_init_window();

#endif
