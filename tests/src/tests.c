/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:36:03 by pierre            #+#    #+#             */
/*   Updated: 2019/02/12 20:06:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ft_math/matrix.h"

int					main(void)
{
	t_matrix44_d	m1;
	t_matrix44_d	m2;
	t_matrix44_d	m3;
	uint8_t			c;

	double m1Value[4][4] = {
		{1.2, 3.23, 34.32, 3.3},
		{3.6, 4.53, 34.32, 3.3},
		{334.55, 3.23, 9765.75, 4.3},
		{3224.4, 3.23, 34.55, 3.4}
	};
	double m2Value[4][4] = {
		{123.34, 33.3, 34123.31, 3.4},
		{123.34, 33.3, 34123.31, 3.4},
		{123.34, 33.3, 34123.31, 3.4},
		{123.34, 33.3, 34123.31, 3.4}
	};

	m1 = ft_init44_matrix44_d(m1Value);
	m2 = ft_init44_matrix44_d(m2Value);
	m3 = ft_multiply_matrix44_d(m1, m2);
	
	printf("New matrix:\n");
	c = 0;
	while (c < 4)
	{
		// printf("{%f, %f, %f, %f}\n", m3.matrix[c][0], m3.matrix[c][1], m3.matrix[c][2], m3.matrix[c][3]);
		c++;
	}

	// ft_printf_test();
	return (0);
}
