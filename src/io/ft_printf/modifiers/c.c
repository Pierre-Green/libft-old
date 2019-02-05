/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:21:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 16:10:47 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "wchar.h"

/*
** Flags: 0/-
** Width
** Length: wchar
*/

static void				ft_root_char(t_printf *state)
{
	wchar_t				wc;

	if (state->part.modifier == CAWCH || state->part.length == LENGTH_LONG_INT)
	{
		wc = (wchar_t)state->part.value.i;
		write(state->fd, &wc, sizeof(wc));
	}
	else
		ft_putchar_fd((unsigned char)state->part.value.i, state->fd);
}

void					ft_pfc(t_printf *state)
{
	if (!state->part.width)
		state->part.width = 1;
	if (ft_test_flag(state, FLEFT))
	{
		ft_root_char(state);
		ft_print_blank(state, state->part.width - 1);
	}
	else if (ft_test_flag(state, FFIL0))
	{
		ft_print_0(state, state->part.width - 1);
		ft_root_char(state);
	}
	else
	{
		ft_print_blank(state, state->part.width - 1);
		ft_root_char(state);
	}
}
