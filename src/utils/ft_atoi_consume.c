/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_consume.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:19:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/04 15:21:34 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

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

int				ft_atoi_consume(char **str)
{
	char		neg;
	int			result;

	if (!(ft_is_valid(*str))
		|| !(*str = ft_atoi_shift_ptr(str)))
		return (0);
	neg = 0;
	if (**str == '-')
	{
		(*str)++;
		neg = 42;
	}
	result = 0;
	while (**str && ft_isdigit(**str))
	{
		result += **str - '0';
		(*str)++;
		if (**str && ft_isdigit(**str))
			result *= 10;
	}
	if (neg)
		result = -result;
	return (result);
}
