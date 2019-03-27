/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:14:00 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 21:23:31 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/matrix.h"
#include <stdio.h>

void					ft_mat44d_debug(t_matrix44_d self)
{
	t_mat44_d_data		m;

	m = self.raw;
	printf("|%f, %f, %f, %f|\n|%f, %f, %f, %f|\n|%f, %f, %f, %f|\n|%f, %f, %f, %f|\n",
			m.v00, m.v01, m.v02, m.v03, m.v10, m.v11, m.v12, m.v13,
			m.v20, m.v21, m.v22, m.v23, m.v30, m.v31, m.v32, m.v33);
}
