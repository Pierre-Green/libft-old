/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:59:45 by pierre            #+#    #+#             */
/*   Updated: 2019/02/08 18:48:40 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

static void				ft_print_octal(t_printf *state, uintmax_t i, size_t p_length, size_t length)
{
	if (p_length > length)
		ft_print_0(state, p_length - length);
	else if (ft_test_flag(state, FALTR))
		ft_putchar_fd('0', state->fd);
	ft_putnbr_fd(i, state->fd);
}

/*
** Flags: #/-/0
** Width
** Precision
*/
void					ft_pfo(t_printf *state)
{
	uintmax_t			i;
	size_t				length;
	size_t				p_length;
	size_t				width;

	i = (uintmax_t)ft_decimal2octal(state->part.value.i);
	length = ft_count_digits_int(i);
	if (ft_test_flag(state, FALTR))
		length++;
	p_length = length;
	if (state->part.precision > length)
		p_length = state->part.precision;
	width = p_length;
	if (state->part.width > p_length)
		width = state->part.width;
	if (ft_test_flag(state, FLEFT))
	{
		ft_print_octal(state, i, p_length, length);
		ft_print_blank(state, width - p_length);
	}
	else if (ft_test_flag(state, FFIL0))
	{
		ft_print_0(state, width - p_length);
		ft_print_octal(state, i, p_length, length);
	}
	else
	{
		ft_print_blank(state, width - p_length);
		ft_print_octal(state, i, p_length, length);
	}
	state->length += width;
}
