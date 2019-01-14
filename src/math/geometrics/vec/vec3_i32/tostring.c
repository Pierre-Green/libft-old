/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:07:07 by pguthaus          #+#    #+#             */
/*   Updated: 2019/01/14 20:07:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"
#include "ft_str.h"
#include "ft_utils.h"

char			*ft_vec3_i32_tostring(t_vec3_i32 self)
{
	char		*result;

	result = ft_strnew(40);
	ft_strcpy(result, "(");
	ft_strcat(result, ft_itoa(self.x));
	ft_strcat(result, ", ");
	ft_strcat(result, ft_itoa(self.y));
	ft_strcat(result, ", ");
	ft_strcat(result, ft_itoa(self.z));
	ft_strcat(result, ")");
	return (result);
}
