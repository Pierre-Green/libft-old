/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:44:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/24 23:08:07 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_noph(t_printf *state)
{
	size_t	length;

	length = 0;
	while (*(state->format + length) && *(state->format + length) != FORMAT_BEGIN)
		length++;
	write(state->fd, state->format, length);
	state->length += length;
	state->format += length;
}
