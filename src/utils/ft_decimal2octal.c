/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal2octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 21:28:15 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/13 21:28:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int					ft_decimal2octal(int i)
{
	int				result;
	size_t			j;

	result = 0;
	j = 1;
	while (i != 0)
	{
		result += (i % 8) * j;
		i /= 8;
		j *= 10;
	}
	return (result);
}
