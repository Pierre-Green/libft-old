/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cC.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:21:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/10 20:11:55 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "wchar.h"
#include "ft_wchar.h"

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
	size_t				width;
	size_t				length;

	length = ft_wchar_length((wchar_t)state->part.value.i);
	width = length;
	if (state->part.width > width)
		width = state->part.width;
	if (ft_test_flag(state, FLEFT))
	{
		ft_root_char(state);
		ft_print_blank(state, width - length);
	}
	else if (ft_test_flag(state, FFIL0))
	{
		ft_print_0(state, width - length);
		ft_root_char(state);
	}
	else
	{
		ft_print_blank(state, width - length);
		ft_root_char(state);
	}
	state->length += width;
}
