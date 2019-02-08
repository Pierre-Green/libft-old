/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putl_uint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:28:36 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 16:40:28 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void				ft_putl_uint_fd(uintmax_t i, int fd, size_t l)
{
	uintmax_t		tmp;
	size_t			current;
	size_t			length;

	current = 0;
	while (current < l)
	{
		tmp = i;
		length = l;
		while (length-- != current + 1)
			tmp /= 10;
		ft_putchar_fd(tmp % 10 + '0', fd);
		current++;
	}
}
