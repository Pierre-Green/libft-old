/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:41:27 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 16:47:49 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static char		ft_putnbr_neg(int n, int fd)
{
	if (n >= 0)
	{
		return (42);
	}
	else
	{
		ft_putchar_fd('-', fd);
		return (0);
	}
}

void			ft_putnbrl_fd(int n, int fd, size_t l)
{
	int			tmp;
	size_t		length;
	size_t		current;

	if (ft_putnbr_neg(n, fd))
		n = -n;
	current = 0;
	while (current < l)
	{
		tmp = n;
		length = l;
		while (length-- != current + 1)
			tmp /= 10;
		ft_putchar_fd(-(tmp % 10) + '0', fd);
		current++;
	}
}
