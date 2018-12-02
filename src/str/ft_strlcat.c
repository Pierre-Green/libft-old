/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:36 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:23:32 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	d_length;

	d_length = (size_t)ft_strlen(dst);
	length = d_length + ft_strlen(src);
	if (size <= d_length)
		return (ft_strlen(src) + size);
	while ((d_length < (size - 1)) && *src)
	{
		dst[d_length] = *src++;
		d_length++;
	}
	dst[d_length] = '\0';
	return (length);
}
