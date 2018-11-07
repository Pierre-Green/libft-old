/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:18:38 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/07 16:28:57 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*result;
	int		current;

	length = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char *)malloc((1 + length) * sizeof(char))))
		return (NULL);
	current = 0;
	while (*s1)
		result[current++] = *s1++;
	while (*s2)
		result[current++] = *s2++;
	result[current] = '\0';
	return result;
}