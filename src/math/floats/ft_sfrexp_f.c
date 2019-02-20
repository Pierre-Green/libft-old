/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfrexp_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:56:51 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/20 19:17:03 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/floats.h"

uint32_t			ft_sfrexp_f(float x, int16_t *exp)
{
	t_float		f;

	f.f = x;
	*exp = f.t_fparts.exp - F_EXP_BIAS + 1;
	return (f.t_fparts.frac);
}
