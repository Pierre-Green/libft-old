/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:24:18 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:19:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void				*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while (n)
	{
		*ptr_dest++ = *ptr_src++;
		n--;
	}
	return (dest);
}
