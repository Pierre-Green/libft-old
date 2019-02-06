/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal2octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:49:33 by pierre            #+#    #+#             */
/*   Updated: 2019/02/06 21:52:01 by pierre           ###   ########.fr       */
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
