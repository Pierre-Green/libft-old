/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fF.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:33:47 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/12 18:43:03 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math/floats.h"

void					ft_pffF(t_printf *state)
{
	t_double			d;

	d = ft_sfrexp_d(state->part.value.d);
	ft_printf("Double splitted: sign: %u, exp: %u, frac: %u\n", d.t_dparts.sign, d.t_dparts.exp, d.t_dparts.frac);
}
