/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:01:17 by pierre            #+#    #+#             */
/*   Updated: 2019/02/08 18:06:22 by pguthaus         ###   ########.fr       */
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
void					ft_pfxX(t_printf *state)
{
	state->part.value.ptr = ft_int_to_hex(state->part.value.i);
	if (ft_test_flag(state, FALTR))
		state->part.value.ptr = ft_strjoin("0X", state->part.value.ptr);
	if (state->part.modifier == CUMHX)
		ft_minify(state);
	ft_pfs(state);
}
