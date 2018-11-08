/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:35:41 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/08 18:41:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*area;

	if (!(area = (unsigned char *)malloc(size * sizeof(unsigned char))))
		return (NULL);
	ft_bzero(area, size);
	return (area);
}