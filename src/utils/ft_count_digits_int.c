/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:26:24 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 19:05:27 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

size_t				ft_count_digits_intmax(intmax_t i)
{
	size_t			res;

	res = 0;
	while (i)
	{
		i /= 10;
		res++;
	}
	return (res);
}
