/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:45 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/14 16:54:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_atoi_shift_ptr(char **ptr)
{
	while (**ptr != '\0' && !ft_isdigit(**ptr) && **ptr != '-')
	{
		if ((**ptr == '\e' && *(*ptr + 1) == '0') || (!ISWHITESPACE(**ptr)
			&& **ptr != '\v' && **ptr != '\r' && **ptr != '\f' && **ptr != '+'))
			return (NULL);
		(*ptr)++;
	}
	if (**ptr == '\0')
		return (NULL);
	return (*ptr);
}

int				ft_atoi(const char *nptr)
{
	char		neg;
	char		*ptr;
	int			result;

	if (!(ptr = ft_atoi_shift_ptr((char **)&nptr)))
		return (0);
	neg = 0;
	if (*ptr == '-')
	{
		ptr++;
		neg = 42;
	}
	result = 0;
	while (*ptr && ft_isdigit(*ptr))
	{
		result += *ptr - '0';
		ptr++;
		if (*ptr && ft_isdigit(*ptr))
			result *= 10;
	}
	if (neg)
		result = -result;
	return (result);
}
