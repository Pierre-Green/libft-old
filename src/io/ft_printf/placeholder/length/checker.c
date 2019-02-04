/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:30:16 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 15:49:47 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"
#include "ft_io.h"

t_bool					ft_is_length(t_printf *state)
{
	char				c;

	c = *state->format;
	return (c == LENGTH_SHORT_INT || c == LENGTH_LONG_INT
			|| c == LENGTH_MAX_INT || c == LENGTH_PTRDIF
			|| c == LENGTH_SIZE_T || c == LENGTH_LONG_DOUBLE);
}
