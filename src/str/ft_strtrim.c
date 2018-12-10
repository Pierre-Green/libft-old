/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:42:04 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/10 04:17:36 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_utils.h"

static int	ft_strtrim_len(char const *s, int start)
{
	int		current;
	int		length;

	current = 0;
	length = -1;
	while (s[start + current])
	{
		if (ISWHITESPACE(s[start + current]) && length == -1)
			length = current;
		if (!ISWHITESPACE(s[start + current]) && length != -1)
			length = -1;
		current++;
	}
	return (length != -1 ? length : current);
}

static int	ft_strtrim_start(char const *s)
{
	int		start;

	start = 0;
	while (ISWHITESPACE(s[start]))
		start++;
	return (start);
}

char		*ft_strtrim(char const *s)
{
	int		length;
	int		trim_length;
	int		start;

	if (s)
	{
		length = ft_strlen(s);
		start = ft_strtrim_start(s);
		if ((trim_length = ft_strtrim_len(s, start)) == length)
			return (ft_strdup(s));
		return (ft_strsub(s, start, (size_t)trim_length));
	}
	return (NULL);
}
