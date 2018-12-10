/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:25 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/10 04:17:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	current;
	int		d_length;

	current = 0;
	d_length = ft_strlen(dest);
	while (current < n && src[current] != '\0')
	{
		dest[d_length + current] = src[current];
		current++;
	}
	dest[d_length + current] = '\0';
	return (dest);
}
