/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:23:52 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:20:05 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	while (n)
	{
		*tmp++ = (unsigned char)c;
		n--;
	}
	return (s);
}
