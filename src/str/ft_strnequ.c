/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:40:34 by pguthaus          #+#    #+#             */
/*   Updated: 2018/12/02 19:24:03 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	current;

	if (s1 && s2)
	{
		current = -1;
		while ((size_t)++current < n)
			if (s1[current] != s2[current])
				return (0);
		return (1);
	}
	return (1);
}
