/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:44:59 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/06 21:20:32 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "ft_io.h"
#include "ft_utils.h"

void					ft_print_precised_int(t_printf *state, intmax_t i, size_t length, size_t precision)
{
	if (i < 0)
		ft_putchar_fd('-', state->fd);
	if (precision > length)
		ft_print_0(state, precision - length);
	ft_putnbr_fd(ABS(i), state->fd);
}

void					ft_print_0(t_printf *state, size_t count)
{
	size_t				current;

	current = 0;
	while (current < count)
	{
		write(state->fd, "0", 1);
		current++;
	}
}

void					ft_print_blank(t_printf *state, size_t count)
{
	size_t				current;

	current = 0;
	while (current < count)
	{
		write(state->fd, " ", 1);
		current++;
	}
}

void					ft_print_str(t_printf *state, char *str, size_t length)
{
	write(state->fd, str, length);
}

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
