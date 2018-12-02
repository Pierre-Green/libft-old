/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:24:30 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:19:14 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void				*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			current;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	current = -1;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while (++current < n)
	{
		ptr_dest[current] = ptr_src[current];
		if (ptr_src[current] == (unsigned char)c)
			return ((void *)&ptr_dest[current + 1]);
	}
	return (NULL);
}
