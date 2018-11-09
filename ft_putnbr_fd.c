/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:43:39 by pguthaus          #+#    #+#             */
/*   Updated: 2018/11/09 17:06:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_putnbr_length(int n)
{
	int			length;

	length = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static char		ft_putnbr_neg(int n, int fd)
{
	if (n > 0)
	{
		return (42);
	}
	else
	{
		ft_putchar_fd('-', fd);
		return (0);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int			tmp;
	size_t		length;
	size_t		current;

	if (ft_putnbr_neg(n, fd))
		n = -n;
	length = ft_putnbr_length(n);
	current = 0;
	while (current < length)
	{
		tmp = n;
		while (ft_putnbr_length(tmp) != current + 1)
			tmp /= 10;
		ft_putchar_fd(-(tmp % 10) + '0', fd);
		current++;
	}
}