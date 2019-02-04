/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:39:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 15:22:11 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

void					ft_apply_width(t_printf *state)
{
	if (*state->format == FIELD_WIDTH_PARAM_VALUE)
	{
		state->part.width_p = true;
		state->format++;
	}
	else
		state->part.width = ft_atoi_consume(&state->format);
}
