/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:27:45 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/15 15:13:34 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_valid(char *ptr)
{
	int			current;
	int			count;

	count = 0;
	current = 0;
	while (ptr[current] && !ft_isdigit(ptr[current]))
	{
		if (ptr[current] == '-' || ptr[current] == '+')
			count++;
		current++;
	}
	if (count > 1)
		return (0);
	return (42);
}

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

	if (!(ft_is_valid((char *)nptr))
		|| !(ptr = ft_atoi_shift_ptr((char **)&nptr)))
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
