/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:09:56 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 13:52:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_next_in_va_list(t_printf *state, va_list list)
{
	if (state->part.modifier == CASTR)
		state->part.value.str = va_arg(list, char *);
}

void					ft_next_param(t_printf *state)
{
	ft_next_in_va_list(state, state->it_params);
}

void					ft_iparam(t_printf *state)
{
	va_list				node;
	size_t				current;

	va_copy(node, state->params);
	current = 0;
	while (current < state->part.nu)
		current++;
	ft_next_in_va_list(state, node);
	va_end(node);
}
