/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:21:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 17:45:18 by pguthaus         ###   ########.fr       */
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
	if (state->part.modifier == CAWCH || state->part.length == LENGTH_LONG_INT)
		ft_putwchar_fd((wchar_t)state->part.value.i, state->fd);
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
