/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:21:02 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:46:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx/drawables.h"
#include "ft_str.h"

size_t					mlx_text_width(char *str)
{
	return (ft_strlen(str) * MLX_CHAR_WIDTH);
}
