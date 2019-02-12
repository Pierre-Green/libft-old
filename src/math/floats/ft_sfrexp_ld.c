/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfrexp_ld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:35:51 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/12 18:36:59 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/floats.h"

t_ldouble		ft_sfrexp_ld(long double x)
{
	t_ldouble	ld;

	ld.ld = x;
	return (ld);
}
