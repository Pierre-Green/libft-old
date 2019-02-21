/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:17:22 by pierre            #+#    #+#             */
/*   Updated: 2019/02/21 17:21:36 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_HOOKS_H
# define FT_MLX_HOOKS_H
# include "ft_lst.h"
# include "ft_mlx/window.h"

typedef struct		s_hook_carry
{
	void			*state;
	t_window		*window;

}					t_hook_carry;

int					keyboard_hooks_dispatcher(int keycode, void *p);

int					lkeyboard_hooks_dispatcher(int keycode, void *p);

int					mouse_hooks_dispatcher(int mouse, int x, int y, void *p);

#endif
