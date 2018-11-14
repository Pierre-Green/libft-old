/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:46:24 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/14 18:16:34 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsplitc(char const *s, char c)
{
	int		current;
	int		count;
	int		length;

	current = -1;
	count = 0;
	length = ft_strlen(s);
	while (++current < length)
	{
		if (s[current] == c)
			continue;
		count++;
		while (s[current] != c)
			current++;
	}
	return (count);
}

static int	ft_strsplit_partlen(char const *s, char c, int start)
{
	int		length;

	length = 0;
	while (s[start + length] != c)
		length++;
	return (length);
}

char		**ft_strsplit(char const *s, char c)
{
	int		current;
	int		part;
	char	**result;
	int		ctmp;
	int		partlen;

	if (!s
	|| !(result = (char **)malloc((1 + ft_strsplitc(s, c)) * sizeof(char *))))
		return (NULL);
	current = -1;
	part = 0;
	while ((size_t)++current < ft_strlen(s))
	{
		if (s[current] == c)
			continue;
		partlen = ft_strsplit_partlen(s, c, current);
		if (!(result[part] = (char *)malloc((1 + partlen) * sizeof(char))))
			return (NULL);
		ctmp = 0;
		while (ctmp < partlen)
			result[part][ctmp++] = s[current++];
		result[part++][ctmp] = '\0';
	}
	result[part] = NULL;
	return (result);
}
