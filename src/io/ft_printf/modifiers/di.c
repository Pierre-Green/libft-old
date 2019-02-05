/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:12:02 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 16:37:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

/*
** Flags: 0/-/ /+/'
** Width
** Precision
** Lengths
*/
void					ft_pfdi(t_printf *state)
{
	size_t				length;

	length = ft_count_digits_intmax(state->part.value.i);
	if (ft_test_flag(state, FLEFT))
	{
		// Left
	}
	else if (ft_test_flag(state, FFIL0))
	{
		// Fill with 0
	}
	else if (ft_test_flag(state, FSIGN))
	{
		// Always sign
	}
	else if (ft_test_flag(state, FPOSI))
	{
		// Pos blank
	}
	else if (ft_test_flag(state, FTHOU))
	{
		// Thousands grouping
	}
}
