/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:04:04 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 18:50:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

/*
** Flags: 0/-
** Width
** Precision
*/
void			ft_pfs(t_printf *state)
{
	size_t	length;
	char	*value;

	value = (char *)state->part.value.ptr;
	length = ft_strlen(value);
	if (!state->part.width)
		state->part.width = length;
	if (state->part.precision)
		length = state->part.precision;
	if (ft_test_flag(state, FLEFT))
	{
		ft_print_str(state, value, length);
		ft_print_blank(state, state->part.width - length);
	}
	else if(ft_test_flag(state, FFIL0))
	{
		ft_print_0(state, state->part.width - length);
		ft_print_str(state, value, length);
	}
	else
	{
		ft_print_blank(state, state->part.width - length);
		ft_print_str(state, value, length);
	}
	if (length > state->part.width)
		state->length += length;
	else
		state->length += state->part.width;
}
