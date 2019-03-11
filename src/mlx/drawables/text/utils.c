/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:21:02 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/11 19:22:08 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_str.h"

size_t					mlx_text_width(char *str)
{
	return (ft_strlen(str) * (10));
}

