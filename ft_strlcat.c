/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:36 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/08 17:15:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_length;

	d_length = (size_t)ft_strlen(dst);
	if (size <= d_length)
		return (ft_strlen(src) + size);
	while (d_length < (size - 1))
	{
		dst[d_length] = *src++;
		d_length++;
	}
	dst[d_length] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
