/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

int32_t          ft_vec3_i32_at(t_vec3_i32 self, uint8_t i)
{
    if (i == 0)
        return (self.x);
    if (i == 1)
        return (self.y);
    if (i == 2)
        return (self.z);
    else
        return (0);
}