/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:30:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/29 12:29:37 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

t_bool					ft_is_parameter(t_printf *state)
{
	char 				*pos;

	pos = state->format;
	while (*pos && ft_isdigit(*pos))
	{
		if (*(pos + 1) == PARAMETER_END)
			return (true);
		pos++;
	}
	return (false);
}
