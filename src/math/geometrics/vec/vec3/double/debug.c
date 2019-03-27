/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:11:49 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/27 21:12:59 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"
#include <stdio.h>

void					ft_vec3_d_debug(t_vec3_d self)
{
	printf("(x: %f, y: %f, z: %f\n", self.x, self.y, self.z);
}
