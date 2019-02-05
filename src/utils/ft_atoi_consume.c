/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_consume.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:19:13 by pguthaus          #+#    #+#             */
/*   Updated: 2019/02/05 13:30:21 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int				ft_atoi_consume(char **str)
{
	int			result;

	if (!ft_isdigit(**str))
		return (0);
	result = 0;
	while (**str && ft_isdigit(**str))
	{
		result += **str - '0';
		(*str)++;
		if (**str && ft_isdigit(**str))
			result *= 10;
	}
	return (result);
}
