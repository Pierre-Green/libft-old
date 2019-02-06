/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 22:00:02 by pierre            #+#    #+#             */
/*   Updated: 2019/02/06 22:54:40 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

static void		ft_print_unsignedint(t_printf *state, uintmax_t i, size_t length, size_t p_length)
{
	if (p_length > length)
		ft_print_0(state, p_length - length);
	ft_putnbr_fd(i, state->fd);
}

/*
** Flags: 0/-/'
** Width
** Precision
*/
void			ft_pfu(t_printf *state)
{
	uintmax_t	i;
	size_t		length;
	size_t		p_length;
	size_t		width;

	i = (uintmax_t)state->part.value.i;
	length = ft_count_digits_intmax(i);
	p_length = length;
	if (state->part.precision > length)
		p_length = state->part.precision;
	width = p_length;
	if (state->part.width > width)
		width = state->part.width;
	if (ft_test_flag(state, FLEFT))
	{
		ft_print_unsignedint(state, i, length, p_length);
		ft_print_blank(state, width - p_length);
	}
	else if(ft_test_flag(state, FFIL0))
	{
		ft_print_0(state, width - p_length);
		ft_print_unsignedint(state, i, length, p_length);
	}
	else
	{
		ft_print_blank(state, width - p_length);
		ft_print_unsignedint(state, i, length, p_length);
	}
}
