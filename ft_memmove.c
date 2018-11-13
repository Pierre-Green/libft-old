/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:24:41 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/13 15:31:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			current;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (ptr_src <= ptr_dest)
	{
		while ((int)--n >= 0)
			ptr_dest[n] = ptr_src[n];
	}
	else
	{
		current = -1;
		while (++current < n)
			ptr_dest[current] = ptr_src[current];
	}
	return (dest);
}
