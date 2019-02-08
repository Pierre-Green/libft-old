/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:39:08 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 19:06:13 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

static void				integer(t_printf *state)
{
	char				c;
	
	c = *(state->format);
	if (c == 'd' || c == 'i')
		state->part.modifier = CSINT;
	if (c == 'o')
		state->part.modifier = CUOCT;
	if (c == 'u')
		state->part.modifier = CUINT;
	if (c == 'x')
		state->part.modifier = CUMHX;
	if (c == 'X')
		state->part.modifier = CUHEX;
}

static void				doubled(t_printf *state)
{
	char				c;
	
	c = *(state->format);
	if (c == 'a')
		state->part.modifier = CDMHX;
	if (c == 'A')
		state->part.modifier = CDHEX;
	if (c == 'e')
		state->part.modifier = CDMEX;
	if (c == 'E')
		state->part.modifier = CDEXP;
	if (c == 'f' || c == 'F')
		state->part.modifier = CDDEC;
	if (c == 'g')
		state->part.modifier = CDMGE;
	if (c == 'G')
		state->part.modifier = CDGEN;
}

static void				alpha(t_printf *state)
{
	char				c;
	
	c = *(state->format);
	if (c == 'c')
		state->part.modifier = CACHR;
	if (c == 'C')
		state->part.modifier = CAWCH;
	if (c == 's')
		state->part.modifier = CASTR;
}

void					ft_apply_type(t_printf *state)
{
	integer(state);
	doubled(state);
	alpha(state);
	if (*state->format == 'n')
		state->part.modifier = CCURL;
	if (*state->format == '%')
		state->part.modifier = CXXXX;
	state->format++;
}
