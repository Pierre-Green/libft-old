/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:46 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:20:58 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char		*ft_strchr(const char *s, int c)
{
	int		current;
	char	*tmp;

	current = -1;
	tmp = (char *)s;
	while (tmp[++current])
	{
		if (tmp[current] == c)
			return (&tmp[current]);
	}
	if (c == '\0')
		return (&tmp[current]);
	return (NULL);
}
