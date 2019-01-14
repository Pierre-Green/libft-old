/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:48:48 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:01:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"

long double		ft_vec3_ld_norm(t_vec3_ld self)
{
	return (self.x * self.x + self.y * self.y + self.z * self.z);
}
