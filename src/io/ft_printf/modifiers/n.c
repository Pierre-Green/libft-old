/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:52:52 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 19:00:19 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_pfn(t_printf *state)
{
	intmax_t			*hey;

	hey = (intmax_t *)state->part.value.ptr;
	*hey = state->length;
}
