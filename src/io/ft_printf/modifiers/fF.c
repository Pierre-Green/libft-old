/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fF.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:33:47 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/20 19:27:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math/floats.h"

void					ft_pffF(t_printf *state)
{
	uint64_t			frac;
	int16_t				exp;

	frac = ft_sfrexp_d(state->part.value.d, &exp);
	ft_printf("Double splitted:, exp: %d, frac: %u\n", exp, frac);
}
