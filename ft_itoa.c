/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:20:44 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/09 16:41:51 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_length(int n)
{
	int			length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		length++;
	}
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char			*ft_itoa(int n)
{
	int			length;
	char		*res;
	char		neg;

	length = ft_itoa_length(n);
	if (!(res = (char *)malloc((1 + length) * sizeof(char))))
		return (NULL);
	neg = 42;
	if (n == 0)
		res[0] = '0';
	if (n >= 0)
	{
		neg = 0;
		n = -n;
	}
	res[length] = '\0';
	while (n)
	{
		res[--length] = -(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
