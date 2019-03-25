/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_consume.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:19:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/03/25 16:27:58 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int				ft_atoi_consume(char **str)
{
	int			result;
	t_bool		neg;

	if (!ft_isdigit(**str) && **str != '-')
		return (0);
	neg = FALSE;
	if (**str == '-')
	{
		neg = TRUE;
		(*str)++;
	}
	result = 0;
	while (**str && ft_isdigit(**str))
	{
		result += **str - '0';
		(*str)++;
		if (**str && ft_isdigit(**str))
			result *= 10;
	}
	return (neg ? -result : result);
}
