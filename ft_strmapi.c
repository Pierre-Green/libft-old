/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:48:00 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/14 16:59:51 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		length;
	int		current;

	if (s && f)
	{
		length = ft_strlen(s);
		if (!(result = (char *)malloc((1 + length) * sizeof(char))))
			return (NULL);
		current = -1;
		while (++current < length)
			result[current] = f(current, s[current]);
		result[current] = '\0';
		return (result);
	}
	return (NULL);
}
