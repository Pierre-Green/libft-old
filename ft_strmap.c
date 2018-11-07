/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:55:47 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/07 20:01:12 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	int		current;

	if (!(result = (char *)malloc((1 + ft_strlen(s)) * sizeof(char))))
		return (NULL);
	current = 0;
	while (*s)
		result[current++] = f(*s++);
	result[current] = '\0';
	return (result);
}