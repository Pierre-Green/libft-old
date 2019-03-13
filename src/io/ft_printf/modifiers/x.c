/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:15:42 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:19:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"
#include "ft_str.h"

static void				ft_minify(t_printf *state)
{
	char				*ptr;

	ptr = (char *)state->part.value.ptr;
	while (*ptr)
	{
		if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr += 32;
		ptr++;
	}
}

/*
** Flags: #/0/-
** Width
** Precision
*/

void					ft_pfx(t_printf *state)
{
	state->part.value.ptr = ft_int_to_hex(state->part.value.i);
	if (ft_test_flag(state, FALTR))
		state->part.value.ptr = ft_strjoin("0X", state->part.value.ptr);
	if (state->part.modifier == CUMHX)
		ft_minify(state);
	ft_pfs(state);
}
