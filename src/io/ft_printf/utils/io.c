/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:44:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 14:02:18 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "ft_io.h"

void		ft_print_noph(t_printf *state)
{
	size_t	length;

	length = 0;
	while (*(state->format + length) && *(state->format + length) != FORMAT_BEGIN)
		length++;
	write(state->fd, state->format, length);
	state->format += length;
	state->length += length;
}
