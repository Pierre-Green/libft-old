/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:39:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 16:08:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_push_param(uint8_t flag, t_printf *state)
{
	if ((flag == FLEFT) && (state->part.flags & FFIL0))
		ft_push_param(FFIL0, state);
	if ((flag == FSIGN) && (state->part.flags & FPOSI))
		ft_push_param(FPOSI, state);
	state->part.flags ^= flag;
}

void					ft_apply_flags(t_printf *state)
{
	char c;

	while (ft_is_flags(state))
	{
		c = *state->format;
		if (c == FLAGS_LEFT_JUSTIFY)
			ft_push_param(FLEFT, state);
		if (c == FLAGS_FILL_WITH_0)
			ft_push_param(FFIL0, state);
		if (c == FLAGS_SIGN_OUTPUT)
			ft_push_param(FSIGN, state);
		if (c == FLAGS_POSITIVE_BLANK)
			ft_push_param(FPOSI, state);
		if (c == FLAGS_ALTERNATE_PRINT)
			ft_push_param(FALTR, state);
		if (c == FLAGS_THOUSANDS_GROUPS)
			ft_push_param(FTHOU, state);
		state->format++;
	}
}
