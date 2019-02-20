/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfrexp_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:35:51 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/20 19:17:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/floats.h"

uint128_t		ft_sfrexp_ld(long double x, int16_t *exp)
{
	t_ldouble	ld;

	ld.ld = x;
	*exp = ld.t_ldparts.exp - L_EXP_BIAS + 1;
	return (ld.t_ldparts.frac);
}
