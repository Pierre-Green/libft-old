/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:17:51 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/14 17:06:26 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	int		current;

	if (!(result = (char *)malloc((1 + len) * sizeof(char))))
		return (NULL);
	current = 0;
	while ((size_t)current < len)
	{
		result[current] = s[start + current];
		current++;
	}
	result[current] = '\0';
	return (result);
}
