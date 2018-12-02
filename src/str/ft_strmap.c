/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:55:47 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:23:42 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		current;

	if (s && f)
	{
		if (!(result = (char *)malloc((1 + ft_strlen(s)) * sizeof(char))))
			return (NULL);
		current = 0;
		while (*s)
			result[current++] = f(*s++);
		result[current] = '\0';
		return (result);
	}
	return (NULL);
}
