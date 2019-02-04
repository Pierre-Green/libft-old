/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:39:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 16:00:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_apply_length(t_printf *state)
{
	char				*c;

	c = state->format;
	if (*c == LENGTH_SHORT_INT)
	{
		if (*(c + 1) == *c)
			state->part.length = LCHRI;
		else
			state->part.length = LSHRI;
	}
	if (*c == LENGTH_LONG_INT)
	{
		if (*(c + 1) == *c)
			state->part.length = LLONI;
		else
			state->part.length = LLLOI;
	}
	if (*c == LENGTH_MAX_INT)
		state->part.length = LMAXI;
	if (*c == LENGTH_PTRDIF)
		state->part.length = LPTRD;
	if (*c == LENGTH_SIZE_T)
		state->part.length = LSIZT;
	if (*c == LENGTH_LONG_DOUBLE)
		state->part.length = LLDOU;
	state->format += ((*c == *(c + 1)) ? 2 : 1);
}
