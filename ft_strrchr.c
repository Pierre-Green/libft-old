/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:26:58 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/14 16:38:09 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*tmp;

	length = ft_strlen(s);
	tmp = (char *)s;
	while (length >= 0)
	{
		if (tmp[length] == c)
			return (&tmp[length]);
		length--;
	}
	return (NULL);
}
