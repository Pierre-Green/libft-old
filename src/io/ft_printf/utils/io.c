/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:44:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 17:43:07 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "ft_io.h"

void		ft_print_noph(t_printf *state)
{
	while (*(state->format + state->length) 
			&& *(state->format + state->length) != FORMAT_BEGIN)
		state->length++;
	write(state->fd, state->format, state->length);
	state->format += state->length;
}
