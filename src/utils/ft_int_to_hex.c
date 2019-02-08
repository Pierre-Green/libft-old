/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:07:40 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/08 18:26:29 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_mem.h"
#include "ft_str.h"

char				*ft_int_to_hex(intmax_t i)
{
	char			buff[128];
	size_t			current;
	size_t			reverser;
	intmax_t		tmp;
	char			*res;

	current = 0;
	while (i != 0)
	{
		tmp = i % 16;
		if (tmp < 10)
			buff[current++] = (tmp + 48);
		else
			buff[current++] = (tmp + 55);
		i /= 16;
	}
	res = malloc(current + 1);
	res[current] = '\0';
	reverser = current;
	while (reverser > 0)
	{
		res[current - reverser] = buff[reverser - 1];
		reverser--;
	}
	return (res);
}
