/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:30:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/29 16:34:24 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"
#include "ft_io.h"

t_bool					ft_is_length(t_printf *state)
{
	char				*pos;

	pos = state->format;
	return ((*pos == LENGTH_SHORT && *(pos + 1) == LENGTH_SHORT) 
		|| (*pos == LENGTH_LONG_INT && *(pos + 1) == LENGTH_LONG_INT)
		|| *pos == LENGTH_SHORT
		|| *pos == LENGTH_LONG_INT
		|| *pos == LENGTH_LONG_DOUBLE
		|| *pos == LENGTH_SIZET
		|| *pos == LENGTH_INTMAX
		|| *pos == LENGTH_PTRDIF);
}
