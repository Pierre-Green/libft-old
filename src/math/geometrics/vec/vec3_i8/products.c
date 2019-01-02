/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:36:12 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

t_vec3_i8       ft_vec3_i8_product1(t_vec3_i8 self, int8_t a)
{
    self.x *= a;
    self.y *= a;
    self.z *= a;

    return (self);
}

int8_t         ft_vec3_i8_product2(t_vec3_i8 self, t_vec3_i8 vec)
{
    return (self.x * vec.x + self.y * vec.y + self.z * vec.z);
}