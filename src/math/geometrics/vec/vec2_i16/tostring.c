/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 16:14:40 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/27 16:47:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math/vec.h"
#include "ft_str.h"
#include "ft_utils.h"

char            *ft_vec2_i16_tostring(t_vec2_i16 self)
{
    char        *result;
    
    result = ft_strnew(17);
    ft_strcpy(result, "(");
    ft_strcat(result, ft_itoa(self.x));
    ft_strcat(result, ", ");
    ft_strcat(result, ft_itoa(self.y));
    ft_strcat(result, ")");
    return (result);
}