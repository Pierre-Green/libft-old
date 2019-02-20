/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfrexp_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:35:51 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/20 19:09:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/floats.h"

uint64_t		ft_sfrexp_d(double x, int16_t *exp)
{
	t_double	d;

	d.d = x;
	*exp = d.t_dparts.exp - D_EXP_BIAS + 1;
	return (d.t_dparts.frac | 1L << 52);
}
