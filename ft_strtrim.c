/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:42:04 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/07 17:15:16 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

static int	ft_strtrim_len(char const *s, int start)
{
	int		current;
	int 	length;

	current = 0;
	length = -1;
	while (s[start + current])
	{
		if (IsWhiteSpace(s[start + current]) && length == -1)
			length = current;
		if (!IsWhiteSpace(s[start + current]) && length != -1)
			length = -1;
		current++;
	}
	return (length != -1 ? length : current);
}

static int	ft_strtrim_start(char const *s)
{
	int		start;

	start = 0;
	while(IsWhiteSpace(s[start]))
		start++;
	return (start);
}

char		*ft_strtrim(char const *s)
{
	int		length;
	int		trim_length;
	char	*result;
	int		current;
	int		start;

	length = ft_strlen(s);
	start = ft_strtrim_start(s);
	if ((trim_length = ft_strtrim_len(s, start)) == length)
		return (ft_strdup(s));
	if (!(result = (char *) malloc((1 + trim_length) * sizeof(char))))
		return (NULL);
	current = 0;
	while (current < trim_length)
	{
		result[current] = s[start + current];
		current++;
	}
	result[current] = '\0';
	return (result);
}