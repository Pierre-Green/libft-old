/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:11 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/10 04:17:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char				*ft_strstr(const char *haystack, const char *needle)
{
	unsigned char	*ptr_haystack;
	unsigned char	*ptr_needle;
	int				current;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	ptr_haystack = (unsigned char *)haystack;
	ptr_needle = (unsigned char *)needle;
	while (*ptr_haystack)
	{
		current = 0;
		while (*(ptr_haystack + current) == *(ptr_needle + current))
		{
			if (*(needle + current + 1) == '\0')
				return ((char *)ptr_haystack);
			current++;
		}
		ptr_haystack++;
	}
	return (NULL);
}
