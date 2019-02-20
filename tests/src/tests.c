/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:36:03 by pierre            #+#    #+#             */
/*   Updated: 2019/02/20 19:07:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ft_math/matrix.h"
#include "ft_math/floats.h"
#include <math.h>
#include <stdio.h>

int					main(void)
{
	double			d;
	int				exp;
	int16_t			exp2;
	double			frac;
	uint64_t		frac2;

	d = 122.456;
	frac = frexp(d, &exp);
	printf("frac: %f, exp: %d\n", frac, exp);
	frac2 = ft_sfrexp_d(d, &exp2);
	printf("frac: %lld, exp: %d\n", frac2, exp2);
	// ft_printf_test();
	return (0);
}
