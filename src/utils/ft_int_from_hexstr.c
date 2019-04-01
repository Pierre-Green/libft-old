/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_from_hexstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 21:11:03 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/01 21:45:34 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_str.h"

uintmax_t		ft_int_from_hexstr(char *str)
{
	uintmax_t	res;
	size_t		len;
	size_t		current;

	if (str[0] != '0' || (str[1] != 'x' && str[1] != 'X'))
		return (0);
	str += 2;
	res = 0;
	len = ft_strlen(str);
	current = 0;
	while (current < len)
	{
		if (str[current] >= '0' && str[current] <= '9')
			res += (str[current] - '0') * (1 << (4 * (len - 1 - current)));
		else if (str[current] >= 'A' && str[current] <= 'F')
			res += (str[current] - 55) * (1 << (4 * (len - 1 - current)));
		else
			return (0);
		current++;
	}
	return (res);
}
