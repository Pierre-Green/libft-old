/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:30:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/29 15:44:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"
#include "ft_io.h"

t_bool					ft_is_precision(t_printf *state)
{
	char				*pos;

	pos = state->format;
	if (*pos == PRECISION_BEGIN)
	{
		pos++;
		return (ft_isdigit(*pos) || *pos == PRECISION_PARAM_VALUE);
	}
	return (false);
}
