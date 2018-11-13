/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:05 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/08 18:20:58 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FIXME: YO

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	current;

	current = 0;
	while (current < n && src[current] != '\0')
	{
		dest[current] = src[current];
		current++;
	}
	while (current < n)
		dest[current++] = '\0';
	return (dest);
}
