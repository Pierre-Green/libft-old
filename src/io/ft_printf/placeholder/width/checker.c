/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:30:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 15:11:15 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

t_bool					ft_is_width(t_printf *state)
{
	char				*pos;

	pos = state->format;
	if (*pos == FIELD_WIDTH_PARAM_VALUE)
		return (TRUE);
	return (ft_isdigit(*pos));
}
