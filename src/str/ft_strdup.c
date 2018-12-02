/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:25:34 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:22:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char		*ft_strdup(const char *s1)
{
	char	*result;
	int		current;

	if (!(result = malloc(1 + ft_strlen(s1) * sizeof(char))))
		return (NULL);
	current = 0;
	while (s1[current])
	{
		result[current] = s1[current];
		current++;
	}
	result[current] = '\0';
	return (result);
}
